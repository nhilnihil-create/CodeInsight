#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
  string n;
  cin >> n;
  ll k=n.size();
  vl dp0(k),dp1(k);//dp0[i]はピッタリ、dp1[i]は余分に払う。
  /*高い位から順々に考えていく*/
  rep(i,k){
    ll d=n[i]-'0';
    if(i==0){
      dp0[i]=d;
      dp1[i]=9-d;
    }
    else{
      dp0[i]=min(dp0[i-1]+d,dp1[i-1]+d+2);
      dp1[i]=min(dp0[i-1]+9-d,dp1[i-1]+9-d);
    }
  }
  cout << min(dp0[k-1],dp1[k-1]+2) << endl;
}