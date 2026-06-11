#include <stdio.h>
int main(){
int h,w;
while(1){
scanf("%d",&h);scanf("%d",&w);
if(h==0&&w==0)break;

for(int i=1;i<=h;i++)
{

for(int k=1;k<=w;k++)
{
if(i==1)printf("#");
else if(i<h){
if(k==1)printf("#");
else if(k<w)printf(".");
else if(k==w)printf("#");
}
else if(i==h)printf("#");

}
printf("\n");
}
printf("\n");
}
return 0;
}