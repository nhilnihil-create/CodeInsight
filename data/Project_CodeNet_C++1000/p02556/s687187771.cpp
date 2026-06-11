#include<bits/stdc++.h>
using namespace std;

int w[200005],h[200005];

int main(){
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d%d",&w[i],&h[i]);
  }
  int maxadd=INT_MIN,minadd=INT_MAX,maxsub=INT_MIN,minsub=INT_MAX;
  for(int i=1;i<=n;i++){
    maxadd=max(maxadd,w[i]+h[i]);
    minadd=min(minadd,w[i]+h[i]);
    maxsub=max(maxsub,w[i]-h[i]);
    minsub=min(minsub,w[i]-h[i]);
  }
  int ans=max(maxadd-minadd,maxsub-minsub);
  printf("%d\n",ans);
  return 0;
}