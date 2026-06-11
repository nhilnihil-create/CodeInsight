#include <bits/stdc++.h>

#define ll long long
#define str string
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second

#define vc vector<char>
#define vvc vector<vc>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vvvll vector<vvll>
#define vs vector<str>
#define vvs vector<vs>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define vb vector<bool>
#define vvb vector<vb>
#define rep(i, a, b) for (int i = (a); i < int(b); i++)
#define repi(i, a, b) for (int i = (a); i <= int(b); i++)


using namespace std;
ll INF = LONG_LONG_MAX;
ll mod = 1000000000 + 7;

template <typename T, typename L>
void read(vector<T> & _data, L & _size, bool _shift) {
    _data.resize(_size + (ll)_shift);
    for (ll i = (ll)_shift; i < _size + (ll)_shift; i++)
        cin >> _data[i];
}

template <typename T, typename L>
void read(vector<vector<T>> & _data, L & _rows, L & _cols, bool _shiftRows, bool _shiftCols) {
    _data.resize(_rows + (ll)_shiftRows);
    for (ll i = 0; i < _rows + (ll)_shiftRows; i++)
        _data[i].resize(_cols + (ll)_shiftCols);
    for (ll i = (ll)_shiftRows; i < _rows + (ll)_shiftRows; i++)
        for (ll j = (ll)_shiftCols; j < _cols + (ll)_shiftCols; j++)
            cin >> _data[i][j];
}

template <typename T>
void write(vector<T> & _data, bool _shift) {
    for (ll i = (ll)_shift; i < _data.size(); i++)
        cout << _data[i] << " ";
    cout << endl;
}


//TODO: SOLUTION

ll n;
vll a;
vb been;

ll gcd(ll x, ll y) {
    while (x != 0 && y != 0) {
        if (x > y)
            swap(x, y);
        ll c = y/x;
        y -= c*x;
    }
    return max(x, y);
}

ll gcdall() {
    ll x = a[0];
    rep(i, 1, n) {
        x = gcd(x, a[i]);
    }
    return x;
}

void solve() {
    cin >> n;
    read(a, n, 0);
    been.resize(1e6 + 1, 0);

    bool pairwise = 1;
    for (ll x : a) {
        if (been[x]) {
            pairwise = 0;
            break;
        }
        for (ll d = 2; d * d <= x; d++) {
            if (x % d == 0) {
                if (been[d] || been[x / d]) {
                    pairwise = 0;
                    break;
                }
            }
        }
        for (ll d = 2; d * d <= x; d++) {
            if (x % d == 0) {
                been[d] = been[x / d] = 1;
            }
        }
        if (x != 1)
            been[x] = 1;
        if (pairwise == 0)
            break;
    }

    bool setwise = gcdall() == 1;

    if (pairwise) {
        cout << "pairwise coprime\n";
    }
    else if (setwise) {
        cout << "setwise coprime\n";
    }
    else {
        cout << "not coprime\n";
    }
}


int main() {

    // TODO: Set value of this variable manually
    bool _multipleTestCases = false;

    if (_multipleTestCases) {
        ll t; cin >> t;
        while (t--)
            solve();
    }
    else {
        solve();
    }

    return 0;
}