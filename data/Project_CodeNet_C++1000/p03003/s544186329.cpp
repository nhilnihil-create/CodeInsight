#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) REP(i, 0, n)
#define REP(i, s, e) for (int i = (s); i < (int)(e); i++)
#define repr(i, n) REPR(i, n, 0)
#define REPR(i, s, e) for (int i = (int)(s - 1); i >= (int)(e); i--)
#define pb push_back
#define all(r) r.begin(), r.end()
#define rall(r) r.rbegin(), r.rend()
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;

template <typename T>
T chmax(T &a, const T &b) { return a = (a > b ? a : b); }
template <typename T>
T chmin(T &a, const T &b) { return a = (a < b ? a : b); }

template <typename T>
class BIT
{
private:
    int n, m;
    vector<vector<T>> bit;

public:
    void add(int i, int j, T val)
    {
        for (int i_ = i + 1; i_ < n; i_ += i_ & -i_)
            for (int j_ = j + 1; j_ < m; j_ += j_ & -j_)
                (bit[i_][j_] += val) %= MOD;
    }
    T sum(int i, int j)
    {
        T s = 0;
        for (int i_ = i + 1; i_ > 0; i_ -= i_ & -i_)
            for (int j_ = j + 1; j_ > 0; j_ -= j_ & -j_)
                (s += bit[i_][j_]) %= MOD;
        return s;
    }
    T sum(int lx, int rx, int ly, int ry)
    {
        return ((sum(rx - 1, ry - 1) - sum(lx - 1, ry - 1) - sum(rx - 1, ly - 1) + sum(lx - 1, ly - 1)) % MOD + MOD) % MOD;
    }
    BIT(int sz1, int sz2)
    {
        n = sz1 + 1, m = sz2 + 1;
        bit.resize(n, vector<T>(m, 0));
    }
    BIT(vector<vector<T>> &v)
    {
        n = (int)v.size() + 1, m = (int)v[0].size() + 1;
        bit.resize(n, vector<T>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                add(i, j, v[i][j]);
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << sum(i - 1, i, j - 1, j) << " ";
            }
            cout << "\n";
        }
    }
    void print_sum()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << sum(i - 1, j - 1) << " ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> s(n), t(m);
    rep(i, n) cin >> s[i];
    rep(i, m) cin >> t[i];
    BIT<ll> bit(n+1, m+1);
    bit.add(0, 0, 1);
    rep(i, n) rep(j, m) {
        if(s[i] == t[j]) {
            // cout << i << " " << j << endl;
            bit.add(i+1, j+1, bit.sum(i, j));
        }
    }
    cout << bit.sum(n, m) << endl;
    // bit.print();
    // cout << endl;
    // bit.print_sum();
    return 0;
}