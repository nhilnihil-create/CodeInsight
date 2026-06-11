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
  ll cnt=0;
  rep1(i,n){
    ll p; cin >> p;
    if(i!=p) cnt++;
  }
  cout << (cnt==0||cnt==2 ? "YES":"NO");
  return 0;
}