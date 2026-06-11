#include <stdio.h>
  int main(){
int i,j;
int x[12]={0,31,60,91,121,152,182,213,244,274,305,335};
int n,m;
while(1){
scanf("%d%d",&n,&m);
if(n==0){
break;
}
int q=x[n-1]+m;
q %= 7;
if(q==0){
printf("Wednesday\n");
}else if(q==1){
printf("Thursday\n");
}else if(q==2){
printf("Friday\n");
}else if(q==3){
printf("Saturday\n");
}else if(q==4){
printf("Sunday\n");
}else if(q==5){
printf("Monday\n");
}else if(q==6){
printf("Tuesday\n");
}
}
return 0;
}