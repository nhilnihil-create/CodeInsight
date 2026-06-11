#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

// #define int ll
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'

const int MOD = (int)1e9 + 7;

int main() {
    ll S;

    cin >> S;

    if (S == (ll)1e18) {
        cout << "0 0 0 1000000000 1000000000 0" << endl;
        return 0;
    }

    ll a = (ll)1e9;
    ll b = 1;

    ll c = (ll)1e9 - (S % a);
    ll d = (S / a) + 1;

    debug(S);
    ll s = abs(a * d - b * c);
    debug(s);

    cout << "0 0 " << a << " " << b << " " << c << " " << d << endl;
    return 0;
}
