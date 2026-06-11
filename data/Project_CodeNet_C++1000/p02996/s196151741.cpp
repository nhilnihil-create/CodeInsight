#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,i,now = 0;scanf("%lld",&n);
  pair<ll,ll> P[n];
  for(i=0;i<n;i++) scanf("%lld%lld",&P[i].second,&P[i].first);
  sort(P,P+n);
  for(i=0;i<n;i++){
    now += P[i].second;
    if(now>P[i].first){
      printf("No\n");return 0;
    }
  }
  printf("Yes\n");
}