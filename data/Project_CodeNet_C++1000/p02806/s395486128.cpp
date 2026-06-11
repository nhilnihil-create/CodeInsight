//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  ll n;cin>>n;
  vector<string> s(n);
  vl t(n);
  rep(i,n)cin>>s[i]>>t[i];
  string x;cin>>x;
  bool ok=false;
  ll ans=0;
  rep(i,n){
    if(ok)ans+=t[i];
    if(s[i]==x)ok=true;
  }
  cout<<ans<<endl;
}