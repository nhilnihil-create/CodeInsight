#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    if(c - a - b <= 0) {
        cout << "No" << endl;
    }
    else {
        ll x = (c - a - b) * (c - a - b);
        if(x > 4 * a * b) {
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
    return 0;
}
