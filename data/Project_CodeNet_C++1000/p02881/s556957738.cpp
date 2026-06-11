#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
#define P pair<int, int>
using namespace std;

int main() { 
  ll n;
  cin >> n;
  ll ans = 1e15;
  for(ll i = 1; i * i <= n; i++){
    if(n % i == 0){
      ans = min(ans, (i-1)+(ll)(n/i-1));
      //cout << ans << " " << i << " " << d << endl;
    }
  }
  cout << ans << endl;
}
