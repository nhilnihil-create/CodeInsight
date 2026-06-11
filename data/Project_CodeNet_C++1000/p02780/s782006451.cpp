#include<stdio.h>
int main(void){
  int n,k;
  double ans=0,p[200000],q[200000];
  scanf("%d %d",&n,&k);
  for(int i=0;i<n;i++){
    scanf("%lf",&p[i]);
    p[i]=(p[i]+1)/2;
   
  }
  for(int i=0;i<k;i++){
    q[0]+=p[i];
    ans=q[0];
  }
  for(int i=1;i<n-k+1;i++){
    q[i]=q[i-1]-p[i-1]+p[i+k-1];
    if(ans<q[i]){
      ans=q[i];
    }
  }
  printf("%lf",ans);
  return 0;
}