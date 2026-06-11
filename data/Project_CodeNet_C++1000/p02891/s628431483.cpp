// Marcin Knapik
#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

// #include <ext/pb_ds/assoc_container.hpp> // order_of_key
// #include <ext/pb_ds/tree_policy.hpp> // find by order
// using namespace __gnu_pbds; 
// #define ordered_set tree< int , null_type,less< int >, rb_tree_tag,tree_order_statistics_node_update>  

// const ll MAX_LL = 0xFFFFFFFFFFFFFFFF;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// #define losuj(a, b) uniform_int_distribution<ull>(a, b)(rng)

typedef long double             ld;
typedef long long               ll;
typedef pair<int, int>          ii;
typedef vector<int>             vi;
typedef vector<vi>              vvi;

#define sz(a)                   (int)(a).size()
#define pb                      push_back
#define all(c)                  (c).begin(), (c).end()
#define FOR(i, a)               for (int i = 0; i < (a); i++)
#define f                       first
#define s                       second

template <class T> inline bool setmin(T &a, T b){if (a > b)return a = b, 1;return 0;}
template <class T> inline bool setmax(T &a, T b){if (a < b)return a = b, 1;return 0;}

template<class T> inline T fast(T a,T b,T mod) {ll res = 1; while(b){if(b&1) res = (res*a)%mod;a = (a*a)%mod;b >>= 1;}return res;}
template<class T> istream &operator>>(istream &os, vector<T> &container){for (auto &u : container)os >> u;return os;}
template<class T> ostream &operator<<(ostream &os, const vector<T> &container){for (auto &u : container)os << u << " ";return os;}
template<class T> inline T gcd(T a, T b) { while (b)swap(a %= b, b); return a; }

const ll INF = 1e9 + 7;
const ll mod = 998244353;
const ll BIG_INF = 1e18+7;
const ll N = 1e6+7;
const ll T = 1<<20;

const ld eps = 1e-12;

ll n, m, k, q;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    cin >> k;

    string xd = s;
    sort(all(xd));
    if(xd[0] == xd.back()){
        cout << ((ll) sz(s)) * k / 2 << '\n';
        exit(0);
    }
    vi przedz;
    s.pb('#');

    int last = 0;
    char last_char = s[0];
    for(int i = 0; i < sz(s); i++){
        if(s[i] != last_char){
            przedz.pb(i - last);
            last = i;
        }
        last_char = s[i];
    }
    s.pop_back();
    // cout << przedz << endl;

    if(s[0] == s.back()){
        ll suma = 0;
        for(int i = 1; i < sz(przedz) - 1; i++)
            suma += (przedz[i] / 2) * k;
        cout << suma + ((przedz[0] + przedz.back()) / 2) * (k - 1) + przedz[0] / 2 + przedz.back() / 2 << '\n';
    }
    else{
        ll suma = 0;
        for(int i = 0; i < sz(przedz); i++)
            suma += (przedz[i] / 2) * k;
        cout << suma << '\n';
    }
}   