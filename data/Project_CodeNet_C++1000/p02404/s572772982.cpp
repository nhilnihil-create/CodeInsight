#include <stdio.h>
int main(void){
while(1){
    int h,w;
    scanf("%d%d",&h,&w);
    if(h==0&&w==0)
    break;
    
    int i,j;
    
 
    
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(i!=0&&i!=h-1&&j!=0&&j!=w-1)
            printf(".");
            else
            printf("#");
        }
       printf("\n");
    }
   
    printf("\n");
}
return 0;
}