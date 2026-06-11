#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep(i, s, n) for (ll i = (ll)s; i < (ll)n; i++)
typedef long long ll;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    int res;
    if (a > 9 || b > 9) res = -1;
    else res = a * b;
    cout << res << endl;
}