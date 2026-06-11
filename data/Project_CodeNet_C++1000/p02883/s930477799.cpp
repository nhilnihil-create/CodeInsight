#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
const ll inf = 1001001001001001001;
int main(){
  ll N,K,i;scanf("%lld%lld",&N,&K);
  ll A[N],F[N];
  for(i=0;i<N;i++) scanf("%lld",&A[i]);
  for(i=0;i<N;i++) scanf("%lld",&F[i]);
  sort(A,A+N);
  ll l = -1,r = inf,mid,cnt;//(left,right]
  while(r - l > 1){
    mid = (l+r)/2;
    ll need[N];
    for(i=0;i<N;i++) need[i] = mid/F[i];
    sort(need,need+N);
    cnt = 0;
    for(i=0;i<N;i++) cnt += max(0LL,A[i]-need[i]);
    if(cnt <= K) r = mid;
    else l = mid;
  }
  printf("%lld\n",r);
}
