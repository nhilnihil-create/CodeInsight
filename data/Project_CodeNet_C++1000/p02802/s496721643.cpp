#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define pi 3.14159265359
#define all(i) i.begin(),i.end()
using namespace std;
const long long INF=1e9+7;
const string alp="abcdefghijklmnopqrstuvwxyz"; //26
const string ALP="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
//const ll MOD=998244353LL;
//const ll MOD=1777777777LL;


int main() {
  ll N,M;
  cin>>N>>M;
  vector<pair<ll,string>> a(M);
  bool judge[N];
  rep(i,N) judge[i]=true;
  ll ac=0;
  ll ans=0;
  vl wa(N,0);
  for(int i=0;i<M;i++){
    cin>>a[i].first>>a[i].second;
  }
  for(int i=0;i<M;i++){
    if(a[i].second=="WA"&&judge[a[i].first-1]){
      wa[a[i].first-1]++;
    }
    else if(a[i].second=="AC"&&judge[a[i].first-1]){
      judge[a[i].first-1]=false;
      ac++;
      ans+=wa[a[i].first-1];
    }
  }
  cout<<ac<<" "<<ans<<endl;
}
