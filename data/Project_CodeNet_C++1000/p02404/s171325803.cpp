#include <stdio.h>
int main(void){
while(1){
    int h,w;
    scanf("%d%d",&h,&w);
    if(h==0&&w==0)
    break;
    
    int i,j;
    
    for(i=0;i<w;i++)
    printf("#");
    
    printf("\n");
    
    for(i=2;i<h;i++){
        printf("#");
        for(j=2;j<w;j++){
            printf(".");
        }
        printf("#\n");
    }
    for(i=0;i<w;i++)
    printf("#");
    
    printf("\n\n");
}
return 0;
}