#include<stdio.h>
#include<math.h>
int main()
{
int N;
double x,sum,cou,ave,w,W;
double n[1001]={};
while(1){
sum=0;cou=0;ave=0;w=0;W=0;
scanf("%d",&N);if(N==0)break;
for(int i=0;i<N;i++){
scanf("%lf",&x);n[i]=x;sum+=x;cou++;
}

ave=sum/cou;

for(int i=0;i<N;i++){
w+=(n[i]-ave)*(n[i]-ave);
}
w=w/N;
W=sqrt(w);
printf("%lf\n",W);
}
return 0;
}