#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
using vs = vector<string> ;
#define all(v) v.begin(),v.end()

int main(){
  ll N,M;cin>>N>>M;
  priority_queue<pair<ll,ll>> works;
  vector<pair<ll,ll>> v;
  rep(i,N){
    ll a,b;cin>>a>>b;
    v.push_back(make_pair(b,a));
  }
  sort(all(v),[&](auto const& a,auto const& b){return a.second<b.second;});
  int ans=0,tmp=0;
  for(int i=0;i<=M;++i){
    while(tmp<N && v[tmp].second<=i){
      pair<ll,ll> p = make_pair(v[tmp].first,v[tmp].second);
      works.push(p);
      tmp++;
    }
    if(!works.empty()){
    pair<ll,ll> w = works.top();
    ans += w.first;
    works.pop();
    }
  }
  cout<<ans<<endl;
}