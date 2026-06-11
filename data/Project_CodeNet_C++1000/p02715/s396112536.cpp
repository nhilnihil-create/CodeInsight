#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> pii;
int n, k;
const int N = 1e5 + 5;
ll f[N], res;

ll expo(ll a, ll b) {
    if  (b == 0) return 1;
    if (a == 0) return 0;
    ll temp = expo(a, b / 2);
    temp = (temp * temp) % MOD;
    if (b & 1) temp = (temp * a) % MOD;
    return temp;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = k; i >= 1; --i) {
        f[i] = expo(k / i, n);// f[i] = g[i]: so gcd la boi cua i
        for (int j = 2; j <= k / i; ++j)
            f[i] -= f[j * i];
        f[i] %= MOD;
        if (f[i] < 0) f[i] += MOD;
        res = (res + (f[i] * i)) % MOD;
    }
    cout << res;
    return 0;
}
