#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
int main(){
  int N,i,j,ans = 0;scanf("%d",&N);
  int L[N];
  for(i=0;i<N;i++) scanf("%d",&L[i]);
  sort(L,L+N);
  for(i=0;i<N-2;i++){
    for(j=i+1;j<N-1;j++){
      ans += lower_bound(L,L+N,L[i]+L[j])-L-j-1;
    }
  }
  printf("%d\n",ans);
}