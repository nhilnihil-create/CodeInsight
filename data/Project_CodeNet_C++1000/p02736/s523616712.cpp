/*
 _    _    _______   _    _
| |  / /  |  _____| | |  / /
| | / /   | |       | | / /
| |/ /    | |_____  | |/ /
| |\ \    |  _____| | |\ \
| | \ \   | |       | | \ \
| |  \ \  | |_____  | |  \ \
|_|   \_\ |_______| |_|   \_\

*/
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair < ll, int > PLI;


#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define right(x) x << 1 | 1
#define left(x) x << 1
#define forn(x, a, b) for (int x = a; x <= b; ++x)
#define for1(x, a, b) for (int x = a; x >= b; --x)
#define mkp make_pair
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define y1 kekekek

#define fname ""

const ll ool = 1e18 + 9;
const int oo = 1e9 + 9, base = 1e9 + 7;
const ld eps = 1e-7;
const int N = 1e6 + 6;

int n;
int a[N], cnt[N];

bool check() {
    bool res = 0;
    forn(i, 1, n) {
        if (cnt[n - 1] == cnt[n - i] + cnt[i - 1])
            res ^= (a[i] == 1);
    }
    return res;
}

int main() {
    ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

    #ifdef krauch
        freopen("input.txt", "r", stdin);
    #else
        //freopen(fname".in", "r", stdin);
        //freopen(fname".out", "w", stdout);
    #endif

    cin >> n;
    forn(i, 1, n) {
        char c;
        cin >> c;
        a[i] = c - '1';
    }

    forn(i, 1, n) {
        cnt[i] = cnt[i - 1] + __builtin_ctz(i);
    }

    if (check()) {
        cout << "1\n";
        return 0;
    }

    forn(i, 1, n) {
        if (a[i] == 1) {
            cout << "0\n";
            return 0;
        }
        if (a[i] == 2) a[i] = 1;
    }

    if (check()) {
        cout << "2\n";
        return 0;
    }

    cout << "0\n";

    return 0;
}
