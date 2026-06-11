#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,b) for (ll i=a;i<=ll(b);i++)
using namespace std;

ll ctoi(const char c){if('0'<=c&&c<='9') return (c-'0');return -1;}
#define ALL(x) begin(x),end(x)
  
int main(){
  ll n;
  cin >> n;
  
  ll ans = 1000000000001;
  for(ll i = 1; i <= sqrt(n); i++){
    if(n%i!=0) continue;
    ll m = n/i;
    ll moveDist = (i-1)+(m-1);
    ans = min(ans,moveDist);
  }
  cout << ans << endl;
}