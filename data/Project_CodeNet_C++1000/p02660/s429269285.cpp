#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
#define VEC(type,name,size) vector<type> name(size);in(name)
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__));in(name)
#define vvv(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))
#define SYOU(x) fixed<<setprecision(x) //小数点桁数を指定する
inline int scan(){ return getchar(); }
inline void scan(int &a){ scanf("%d", &a); }
inline void scan(unsigned &a){ scanf("%u", &a); }
inline void scan(long &a){ scanf("%ld", &a); }
inline void scan(long long &a){ scanf("%lld", &a); }
inline void scan(unsigned long long &a){ scanf("%llu", &a); }
inline void scan(char &a){ cin >> a; }
inline void scan(float &a){ scanf("%f", &a); }
inline void scan(double &a){ scanf("%lf", &a); }
inline void scan(long double &a){ scanf("%Lf", &a); }
inline void scan(vector<bool> &vec){ for(unsigned i = 0; i < vec.size(); i++) { int a; scan(a); vec[i] = a; } }
inline void scan(string &a){ cin >> a; }
template<class T> inline void scan(vector<T> &vec);
template<class T, size_t size> inline void scan(array<T, size> &vec);
template<class T, class L> inline void scan(pair<T, L> &p);
template<class T, size_t size> inline void scan(T (&vec)[size]);
template<class T> inline void scan(vector<T> &vec){ for(auto &i : vec) scan(i); }
template<class T, size_t size> inline void scan(array<T, size> &vec){ for(auto &i : vec) scan(i); }
template<class T, class L> inline void scan(pair<T, L> &p){ scan(p.first); scan(p.second); }
template<class T, size_t size> inline void scan(T (&vec)[size]){ for(auto &i : vec) scan(i); }
template<class T> inline void scan(T &a){ cin>>a; }
inline void in(){}
template <class Head, class... Tail> inline void in(Head &head, Tail&... tail){ scan(head); in(tail...); }
inline constexpr ll gcd(ll a,ll b){if(!a||!b)return 0;while(b){ll c=b;b=a%b;a=c;}return a;}
inline constexpr ll lcm(ll a,ll b){if(!a||!b)return 0;return a*b/gcd(a,b);}
inline ll mod(ll val, ll m) {long long res = val % m;if (res < 0) res += m;return res;}
inline int divisor_count(int n) {int j, c = 1;for (int i = 2; i * i <= n; i++, c *= j)for (j = 1; !(n % i); j++) n /= i;return (1 < n) ? c * 2 : c;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;
/* 4方向への隣接頂点への移動を表すベクトル */
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

const long long INF = 1LL << 60;
const ll MOD = 1000000007;
int main(){
    LL(n);
    ll ans = 0LL;
    ll x = n;
    for(ll i = 2; i*i <=x; ++i) {
        ll cnt = 0LL;
        while(n%i == 0) {
            cnt++;
            n /= i;
        }
        for(int j = 1; cnt >= j; ++j) {
            ans++;
            cnt -=j;
        }
    }
    if(n > 1) {
        ans++;
    }
    cout << ans << endl;

    return 0;
}