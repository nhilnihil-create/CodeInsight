#include <stdio.h>
int main(){
int h,w;
while(1){
scanf("%d",&h);scanf("%d",&w);
if(h==0&&w==0)break;

for(int i=0;i<h;i++)
{
for(int k=0;k<w;k++)
{
printf("#");
}
printf("\n");
}
printf("\n");
}
return 0;
}