#include<bits/stdc++.h>
#include"atcoder/all"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
using namespace atcoder;
typedef long long ll;
int main(){
  ll N,Q,i,a,t,l,r;scanf("%lld%lld",&N,&Q);
  fenwick_tree<ll> B(N);
  for(i=0;i<N;i++){
    scanf("%lld",&a);
    B.add(i,a);
  }
  for(i=0;i<Q;i++){
    scanf("%lld%lld%lld",&t,&l,&r);
    if(t == 0) B.add(l,r);
    else printf("%lld\n",B.sum(l,r));
  }
}