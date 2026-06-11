#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    ll N, K; cin >> N >> K;
    ll ans = 0;
    for (ll i = K; i <= N + 1; i++) {
        ans += i * N - i * (i - 1) + 1;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}