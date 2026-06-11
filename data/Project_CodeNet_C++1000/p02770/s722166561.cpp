#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(int)(a); (i)<(int)(b); ++(i))
#define rFor(i, a, b) for(int (i)=(int)(a)-1; (i)>=(int)(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<int, lint> pil;
typedef pair<lint, lint> pll;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}
template<class T> T div_floor(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>=0 ? a/b : (a+1)/b-1;
}
template<class T> T div_ceil(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>0 ? (a-1)/b+1 : a/b;
}

constexpr lint mod = 1e9+7;
constexpr lint INF = mod * mod;
constexpr int MAX = 100010;

int main(){
    int K, q;
    scanf("%d%d", &K, &q);
    lint d[K];
    rep(i, K) scanf("%lld", &d[i]);
    rep(_, q){
        lint n, x, m;
        scanf("%lld%lld%lld", &n, &x, &m);
        x %= m;
        lint td[K], sum = 0, zero = 0, zero_sum = 0;
        rep(i, K){
            td[i] = d[i] % m;
            sum += td[i];
            if(td[i] == 0) ++zero;
        }

        lint a = x + (n-1)/K * sum;
        zero_sum += (n-1)/K * zero;
        for(int i=0; i<=(n-1)%K-1; ++i){
            a += td[i];
            if(td[i] == 0) ++zero_sum;
        }

        printf("%lld\n", n-1 - (a/m - x/m) - zero_sum);
    }
}