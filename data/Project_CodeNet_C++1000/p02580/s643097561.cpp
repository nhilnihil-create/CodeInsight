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

ll h, w, m;
vll x, y;
map<ll, ll> incol;
map<ll, ll> inrow;
map<ll, ll> cnt;

void solve() {
    cin >> h >> w >> m;
    x.resize(m); y.resize(m);
    ll maxrow = 0, maxcol = 0;

    rep(i, 0, m) {
        cin >> x[i] >> y[i];
        if (inrow.count(x[i]))
            inrow[x[i]]++;
        else
            inrow[x[i]] = 1;
        if (incol.count(y[i]))
            incol[y[i]]++;
        else
            incol[y[i]] = 1;
    }

    rep(i, 0, m) {
        maxrow = max(maxrow, inrow[x[i]]);
        maxcol = max(maxcol, incol[y[i]]);
    }

    ll num = 0;
    for (auto it = incol.begin(); it != incol.end(); it++) {
        if (it->second == maxcol)
            num++;
    }

    bool suc = 0;
    rep(i, 0, m) {
        if (inrow[x[i]] == maxrow && incol[y[i]] == maxcol) {
            if (cnt.count(x[i]))
                cnt[x[i]]++;
            else
                cnt[x[i]] = 1;
        }
    }

    rep(i, 0, m) {
        if (inrow[x[i]] == maxrow && cnt[x[i]] != num) {
            suc = 1;
            break;
        }
    }

    if (suc)
        cout << maxrow + maxcol;
    else
        cout << maxrow + maxcol - 1;
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