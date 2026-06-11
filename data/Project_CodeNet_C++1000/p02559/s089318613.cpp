#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"
template<class T> void chmax(T &a, const T b){ a = max(a, b); }
template<class T> void chmin(T &a, const T b){ a = min(a, b); }

template<typename T>
struct BinaryIndexedTree {
private:
    int n;
    vector<T> bit;
    
public:
    BinaryIndexedTree(int _n) : n(_n + 1), bit(n + 1, 0){}
    
    T sum(int idx) {
        T s(0);
        for(int x = idx + 1; x > 0; x -= (x & -x)) s += bit[x];
        return s;
    }
    
    void add(int idx, T a) {
        for(int x = idx + 1; x <= n; x += (x & -x)) bit[x] += a;
    }
    
    T query(int l, int r) {
        return sum(r - 1) - sum(l - 1);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n, q;
    cin >> n >> q;
    BinaryIndexedTree<ll> ft(n);
    rep(i, n) {
        ll a;
        cin >> a;
        ft.add(i, a);
    }
    rep(i, q) {
        ll t, a, b;
        cin >> t >> a >> b;
        if (t == 0) {
            ft.add(a, b);
        }
        else {
            cout << ft.query(a, b) << endl;
        }
    }
    return 0;
}
