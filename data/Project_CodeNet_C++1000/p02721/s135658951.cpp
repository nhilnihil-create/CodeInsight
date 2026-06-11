#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  ll N,K,C;
  cin>>N>>K>>C;
  string S;
  cin>>S;
  vector<ll> v;
  for(ll i = 0LL; i < N; i++){
    if(S[i]=='o') v.push_back(i);
  }
  ll t=v.size();
  vector<ll> work(K);
  work[0]=0;
  for(ll i = 1LL; i < K; i++){
    work[i]=(ll)(upper_bound(v.begin(),v.end(),v[work[i-1]]+C)-v.begin());
  }
  vector<ll> ans;
  for(ll i = K-1LL; i >=0; i--){
    if(i==K-1) {
      if(work[i]==t-1LL) ans.push_back(v[work[i]]);
      work[i]=t-1LL;
    }
    else{
      auto ite = lower_bound(v.begin(),v.end(),v[work[i+1]]-C);
      if((ll)(ite-v.begin()-1)==work[i]) ans.push_back(v[work[i]]);
      work[i]=(ll)(ite-v.begin()-1);
    }
  }
  for(ll i = (ll)ans.size()-1; i >=0;i--){
    cout<<ans[i]+1<<endl;
  }
}