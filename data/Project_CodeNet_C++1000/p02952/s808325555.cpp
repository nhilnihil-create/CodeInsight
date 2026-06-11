#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); ++i)
#define rep1(i,n) for (ll i=1; i<=(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";
const ll mod = 998244353;
const double e = 0.000000001;
ll dp[105][2][5];
int main(){
  ll n; cin >> n;
  ll ans = 0;
  if(n>=10000){
    ans+=min(n-10000+1,(ll)90000);
  }
  if(n>=100){
    ans+=min(n-100+1,(ll)900);
  }
  if(n>=1){
    ans+=min(n,(ll)9);
  }
  cout << ans;
  return 0;
}