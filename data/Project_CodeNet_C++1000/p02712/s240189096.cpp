#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   ll n; cin >> n;
   ll ans = (n*(n+1))/2;
   ans -= (((n/3)*((n/3)+1))/2)*3;
   ans -= (((n/5)*((n/5)+1))/2)*5;
   ans += (((n/15)*((n/15)+1))/2)*15;
   cout << ans << endl;
}