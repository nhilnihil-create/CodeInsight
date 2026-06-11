#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
int main(){
  ll N,i;scanf("%lld",&N);
  ll A[N],ans[N];
  for(i=0;i<N;i++) scanf("%lld",&A[i]);
  ans[0] = accumulate(A,A+N,0LL);
  for(i=1;i<N;i+=2) ans[0] -= A[i]*2;
  for(i=1;i<N-1;i++) ans[i] = A[i-1]*2-ans[i-1];
  ans[N-1] = A[N-1]*2-ans[0];
  for(i=0;i<N;i++) printf("%lld ",ans[i]);
  printf("\n");
}