#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
while(1){
int i,j,r,c,cnt,ans=0,sum,l;
static int t[10][10000];
scanf("%d%d",&r,&c);
if(r==0&&c==0)return 0;
for(i=0;i<r;i++){
for(j=0;j<c;j++){
scanf("%d",&t[i][j]);
}
}
for(l=0;l<(1<<r);l++){
sum=0;
for(j=0;j<c;j++){
cnt=0;
for(i=0;i<r;i++){
cnt+=(t[i][j]!=((l>>i)&0x01));
}
sum+=max(r-cnt,cnt);
}
ans=max(ans,sum);
}
printf("%d\n",ans);
}
return 0;
}

