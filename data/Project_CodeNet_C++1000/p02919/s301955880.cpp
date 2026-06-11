#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF 2100000000
#define MOD 1000000007

int main(){
  ll N;
  cin>>N;
  vector<pair<ll,ll>> P(N);
  for(ll i=0;i<N;i++){
    cin>>P.at(i).first;
    P.at(i).second=i;
  }
  sort(P.begin(),P.end());
  reverse(P.begin(),P.end());

  multiset<ll> S;
  S.insert(-1);
  S.insert(-1);
  S.insert(N);
  S.insert(N);
  ll ans=0;
  for(ll i=0;i<N;i++){
    auto iter=S.upper_bound(P.at(i).second);
    iter--;
    iter--;
    ll a1=*iter;
    iter++;
    ll a2=*iter;
    iter++;
    ll a3=*iter;
    iter++;
    ll a4=*iter;
    ans+=(ll)P.at(i).first*(((ll)a2-(ll)a1)*((ll)a3-(ll)P.at(i).second)+((ll)a4-(ll)a3)*((ll)P.at(i).second-(ll)a2));
    S.insert(P.at(i).second);
  }
  cout<<ans<<endl;
}
