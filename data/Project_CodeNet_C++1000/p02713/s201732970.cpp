#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
//gcd(x, y) -> xとyの最大公約数
ll gcd(ll x, ll y){
    return y ? gcd(y, x % y) : x;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int k; cin >> k;
   ll ans = 0;
   rep(a,k)rep(b,k)rep(c,k)ans+=gcd(gcd(a+1,b+1),c+1);
   cout << ans << endl;
}