#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef long double ld;

int main(){
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    for(ll i = K; i <= N + 1; i++){
        ll min = (i - 1) * i / 2;
        ll max = (2 * N - i + 1) * i /2;
        ll sum = ((max - min + 1) % MOD);
        ans += sum;
        ans %= MOD;
    }
    cout << ans << endl;
}
