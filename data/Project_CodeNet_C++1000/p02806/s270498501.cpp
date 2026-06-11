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
  ll N;
  cin>>N;
  string s[N];
  ll t[N];
  rep(i,N) cin>>s[i]>>t[i];
  string x;
  cin>>x;
  ll check;
  ll ans=0;
  rep(i,N){
    if(x==s[i]){
      check=i+1;
    }
  }
  for(int i=check;i<N;i++){
    ans+=t[i];
  }
  cout<<ans<<endl;
}