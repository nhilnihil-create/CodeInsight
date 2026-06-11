#include<stdio.h>

int main(){
	int x[10];
    for(int i=0; i<5; i++) scanf("%d", &x[i]);
    if(x[0]==0) printf("%d",1);
    if(x[1]==0) printf("%d", 2);
    if(x[2]==0) printf("%d", 3);
    if(x[3]==0) printf("%d", 4);
    if(x[4]==0) printf("%d", 5);
    return 0;
}    
