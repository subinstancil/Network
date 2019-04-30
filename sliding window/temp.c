#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h> 
#include <sys/types.h> 
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 
 
int main()
{
    int w = 3;
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli; 
    int w,i,f,frames[50];
    char buff[MAX]; 
    int n; 













     sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(PORT); 
  
    // connect the client socket to server socket 
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("connection with the server failedstdlibstdlib...\n"); 
        exit(0); 
    } 
    else{
        printf("connected to the server..\n"); 
    











 
    // printf("Enter window size: ");
    // scanf("%d",&w);
 
    printf("\nEnter number of frames to transmit: ");
    scanf("%d",&f);
 
    printf("\nEnter %d frames: ",f);
 
    for(i=1;i<=f;i++)
        scanf("%d",&frames[i]);
 
    // printf("\nWith sliding window protocol the frames will be sent in the following manner (assuming no corruption of frames)\n\n");
    // printf("After sending %d frames at each stage sender waits for acknowledgement sent by the receiver\n\n",w);
    bzero(buff, sizeof(buff)); 
    for(i=1;i<=f;i++)
    {
        if(i%w==0)
        {
            printf("%d\n",frames[i]);
            // printf("Acknowledgement of above frames sent is received by sender\n\n");
        }
        else
            printf("%d ",frames[i]);
    }
 
    if(f%w!=0)
        // printf("\nAcknowledgement of above frames sent is received by sender\n");
 
    }
    return 0;
}