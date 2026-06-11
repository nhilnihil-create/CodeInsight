#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
int main(){
  int N,i,j;scanf("%d",&N);
  int a[N+1],ans[N+1],sum;
  for(i=1;i<=N;i++) scanf("%d",&a[i]);
  for(i=N;i>=1;i--){
    sum = 0;
    for(j=i+i;j<=N;j+=i) sum ^= ans[j];
    ans[i] = sum^a[i];
  }
  printf("%d\n",accumulate(ans+1,ans+N+1,0));
  for(i=1;i<=N;i++){
    if(ans[i]) printf("%d ",i);
  }
  printf("\n");
}
