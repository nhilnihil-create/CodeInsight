#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <functional>

using namespace std;

#define fst first
#define scd second
#define PB push_back
#define MP make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define omajinai ios::sync_with_stdio(false);cin.tie(0)
#define rep(i,x) for(int i=0;i<(int)(x);++i)
#define rep1(i,x) for(int i=1;i<=(int)(x);++i)
#define rrep(i,x) for(int i=(int)x-1;i>=0;--i)
#define rrep1(i,x) for(int i=(int)x;i>=1;--i)

using ll=long long;
using ld=long double;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int, int>;
using vpii=vector<pii>;

template<class T,class U>ostream&operator<<(ostream&os,const pair<T,U>p){os<<"("<<p.fst<<", "<<p.scd<<")";return os;}
template<class T>ostream&operator<<(ostream&os,const vector<T>v){rep(i,v.size()){if(i)os<<", ";os<<v[i];}return os;}
template<typename T>T&max(T&a,T&b){if(a>=b)return a;return b;}
template<typename T>T&min(T&a,T&b){if(a < b)return a;return b;}
template<typename T>bool chmax(T&a,T b){if(a < b){a=b;return true;}return false;}
template<typename T>bool chmin(T&a,T b){if(a > b){a=b;return true;}return false;}
constexpr ll TEN(ll n){return n==0?1:10ll*TEN(n-1);}

constexpr ll inf = TEN(9)+5;
constexpr ll linf = 3*TEN(18);

const int mod = TEN(9)+7;

ll inv[200010];
ll fac[200010], fac_inv[200010];
ll C(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return ((fac[n] * fac_inv[k] % mod) * fac_inv[n - k]) % mod;
}
void comb_init()
{
    int N = 200005;
    inv[1] = 1;
    for (int i = 2; i <= N; ++i) {
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    }
    fac[0] = fac_inv[0] = 1;
    for (int i = 1; i <= N; ++i) {
        fac[i] = (fac[i - 1] * i) % mod;
        fac_inv[i] = (fac_inv[i - 1] * inv[i]) % mod;
    }
}

signed main()
{
    comb_init();
    int S; cin >> S;

    int ans = 0;
    int cur = 0;

    while (S - 2 > 0) {
        S -= 2;

        ans += C(S - 1, cur);
        ans %= mod;

        cur++;
    }

    printf("%d\n", ans);
}
