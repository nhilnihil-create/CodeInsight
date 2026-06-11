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

template<typename T>
struct Doubling {
private:
    const int LOG;
    vector<vector<T>> table;
    
public:
    Doubling(int n, long long mv) : LOG(64 - __builtin_clzll(mv)) {
        table.resize(LOG, vector<T>(n, -1));
    }
    
    void set_next(int k, T x) {
        table[0][k] = x;
    }
    
    void build() {
        for(int k = 0; (k + 1) < LOG; k++) {
            for(int i = 0; i < table[k].size(); i++) {
                if (table[k][i] == -1) {
                    table[k + 1][i] = -1;
                }
                else {
                    table[k + 1][i] = table[k][table[k][i]];
                }
            }
        }
    }
    
    T query(int k, long long t) {
        for(int i = LOG - 1; i >= 0; i--) {
            if ((t >> i) & 1) {
                k = table[i][k];
            }
        }
        return k;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    Doubling<ll> dbl(n, k);
    rep(i, n) dbl.set_next(i, a[i] - 1);
    dbl.build();
    cout << (dbl.query(0, k) + 1) << endl;
    return 0;
}
