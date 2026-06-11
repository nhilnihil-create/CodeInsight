#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll S;
    cin >> S;
    for (ll i = floor(sqrt(S)); i <= pow(10, 9); i++) {
        if (0 <= i * i - S && i * i - S <= pow(10, 9)) {
            cout << 0 << " " << 0 << " " << i << " " << i * i - S << " " << 1
                 << " " << i << endl;
            break;
        }
    }

    return 0;
}