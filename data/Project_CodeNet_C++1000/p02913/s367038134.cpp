#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const ll MOD2=998244353;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

int main() {
  ll n;
  string s;
  cin >> n >> s;
  ll ans=0;
  FOR(D,1,n){
    ll cnt=0;
    rep(i,n-D){
      if(s[i]==s[i+D]&&cnt<D){
        cnt++;
      }
      else{
        cnt=0;
      }
      ans=max(ans,cnt);
    }
  }
  cout << ans << endl;
}
