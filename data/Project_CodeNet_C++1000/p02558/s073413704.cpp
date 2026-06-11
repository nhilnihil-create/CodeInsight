#pragma region header
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rev(i, n) for(int i = (int)(n - 1); i >= 0; i--)
#define rev1(i, n) for(int i = (int)(n); i > 0; i--)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define resort(v) sort((v).rbegin(), (v).rend())
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
using ll = long long;
using P = pair<int, int>;
/* ----------------よく使う数字や配列----------------- */
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
constexpr ll mod = 1e9+7;
constexpr int inf = INT32_MAX/2;
constexpr ll INF = LLONG_MAX/2;
constexpr long double eps = DBL_EPSILON;
constexpr long double pi = 3.141592653589793238462643383279;
/* ----------------------end----------------------- */

/* --------------------テンプレート------------------ */
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
/* ----------------------end----------------------- */

/* --------------------ライブラリ-------------------- */
ll fact(int i) {       //階乗
    if (i == 0) return 1;
    return (fact(i - 1)) * i % mod;
}
ll gcd(ll a, ll b) {        //最大公約数
    if(b == 0) return a;
    return gcd(b, a % b); 
}
ll lcm(ll a, ll b) {      //最小公倍数
    return a / gcd(a, b) * b ;
}
int keta(ll n) {        //桁数を求める
    if(n == 0) return 1;
    int count = 0;
    while(n != 0) {
        n /= 10;
        count++;
    }
    return count;
}
ll ketasum(ll n) {    //各桁の和
    ll sum = 0;
    while(n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
/* ----------------------end----------------------- */
#pragma endregion
struct UnionFind {
    vi par,size;
    UnionFind(int n) {
        par.resize(n);
        size.resize(n,1);
        rep(i, n) par[i]=i;
    }
    bool same(int x,int y) {
        return find(x)==find(y);
    }
    int consize(int k) {
        return size[find(k)];
    }
    int find(int k) {
        if(par[k]==k) return k;
        return par[k]=find(par[k]);
    }
    bool unite(int x,int y) {
        if(same(x,y)) return false;
        if(consize(x)<consize(y)) {
            par[find(x)]=find(y);
            size[y]+=size[x];
        }
        else {
            par[find(y)]=find(x);
            size[x]+=size[y];
        }
        return true;
    }
};
signed main() {
    int n,q;cin >> n >> q;
    UnionFind uf(n);
    rep(i, q) {
        int a,b,c;cin >> a >> b >> c;
        if(a) cout << uf.same(b,c) << endl;
        else uf.unite(b,c);
    }
    return 0;
}