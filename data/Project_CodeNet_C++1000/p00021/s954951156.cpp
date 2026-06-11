#include<stdio.h>
#include<math.h>
 
int main(){
    float x1,x2,x3,x4,y1,y2,y3,y4;
    float a1=0.0,a2=0.0;
    int n,i;
     
    scanf("%d",&n);
     
    for(i=0;i<n;i++){
        scanf("%f %f %f %f %f %f %f %f",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
            a1=(y2-y1)/(x2-x1);
            a2=(y4-y3)/(x4-x3);
         
            if( a1==a2 )printf("YES\n");
            else printf("NO\n");
    }
return 0;
}