#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int n, k, s;
    cin >> n >> k >> s;
    rep(i, k) {
        cout << s << endl;
    }
    if(s != 1) {
        rep(i, n - k) {
            cout << s - 1 << endl;
        }
    }
    else {
        rep(i, n - k) {
            cout << s + 1 << endl;
        }
    }
    return 0;
}
