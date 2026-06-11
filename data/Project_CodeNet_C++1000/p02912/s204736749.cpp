#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
int main(){
  ll N,M,i,a,f;scanf("%lld%lld",&N,&M);
  priority_queue<ll> q;
  for(i=0;i<N;i++){
    scanf("%lld",&a);
    q.push(a);
  }
  for(i=0;i<M;i++){
    f = q.top();q.pop();
    f /= 2;q.push(f);
  }
  ll ans = 0;
  for(i=0;i<N;i++){
    ans += q.top();q.pop();
  }
  printf("%lld\n",ans);
}