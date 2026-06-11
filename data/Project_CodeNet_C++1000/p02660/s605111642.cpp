#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

using pii = pair<int, int>; using vpii = vector<pii>;
using vi = vector<int>; using vvi = vector<vi>;
using ll = long long;
using pll = pair<ll, ll>; using vpll = vector<pll>;
using vll = vector<ll>; using vvll = vector<vll>;

const ll MX = 1000000;
bool p[MX + 5];

int main() {
    FOR(i, 2, MX) {
        if (p[i]) continue;
        for (int j =  i +i; j <= MX; j += i)
            p[j] = 1;
    }
    ll n, ans = 0; cin >> n;
    for (int i = 2; i <= MX; i++) {
        if (p[i]) continue;
        ll t = i;
        while (n % t == 0)
            n /= t, t *= i, ans++;
    }
    if (n > MX) ans++;
    cout << ans << endl;
}