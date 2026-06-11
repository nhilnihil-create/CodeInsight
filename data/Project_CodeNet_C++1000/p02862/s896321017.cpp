#include<iostream>
#include<vector>
#include<map>
#include<math.h>
#include<algorithm>

#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rep2(i,a,n) for(int i = (int)(a); i <= (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n-1); i > -1; i--)
#define rrep2(i,n,a) for(int i = (int)(n); i >= (int)(a); i--)

#define fi first
#define se second

using namespace std;

using ll = long long;
using v_int = vector<int>;
using v2_int = vector<v_int>;
using v_ll = vector<ll>;
using v2_ll = vector<v_ll>;
using v_string = vector<string>;
using v_bool = vector<bool>;
using v2_bool = vector<v_bool>;
using pii = pair<int, int>;
using mii = map<int, int>;

const double PI = 3.1415926535897932;
const int INF = (int)2e9;
const ll LINF = (ll)2e18;
const ll MOD = 1000000007;
const int dc[8] = {1, -1, 0,  0, 1, -1,  1, -1};
const int dr[8] = {0,  0, 1, -1, 1,  1, -1, -1};

template<typename T, typename U> inline
ostream& operator<<(ostream &o, pair<T,U> &p) {
    return o << "{" << p.first << "," << p.second << "}";
}
template<typename T> inline
istream& operator>>(istream &is, vector<T> &vec) {
    for(auto &v : vec) { is >> v; }
    return is;
}
template<typename T> inline
ostream& operator<<(ostream &os, vector<T> &vec) {
    for(auto &v : vec) { os << v << ",";}
    return os;
}
template<typename T> inline
ostream& operator<<(ostream &os, vector<vector<T> > &mat) {
    for(auto &row : mat) { os << row << endl; }
    return os;
}

template<typename T> inline
void chmin(T &a, T b) { a = min(a, b); }
template<typename T> inline
void chmax(T &a, T b) { a = max(a, b); }

template<typename T>
T ModPow(T s, T n)
{
    T res = 1;

    while(n) {
        if (n & 1) { 
            res *= s;
            res %= MOD;
        }
        s *= s;
        s %= MOD;
        n >>= 1;
    }
    return res;
}

template<typename T>
T ModInv(T n) {
    return ModPow(n, MOD - 2);
}

template<typename T>
T ModnCr(T n, T r) 
{
    T x = 1, y = 1;
    
    rep(i, r) {
        x *= n-i;
        x %= MOD;

        y *= r-i;
        y %= MOD;
    }

    T rtn = (x * ModInv(y)) % MOD;
    return rtn;
}

ll func(ll n) 
{
    ll res = 1;
    while(n) {
        res *= n;
        res %= MOD;
        n--;
    }
    return res;
}

int main(void)
{
    int x,y;
    cin >> x >> y;

    int d = 2 * x - y;
    if(d%3 != 0) {
        cout << 0 << endl; 
    } else {
        ll a = x - (2 * d) / 3;
        ll b = d / 3;
        if(a < 0 || b < 0) { cout << 0 << endl; return 0; }
        ll ans = ModnCr(a+b,b);
        cout << ans << endl;
    }
    return 0;
} /*atcoder*/

