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
    int n;
    scanf("%d", &n);
    lint x[n], y[n];
    rep(i, n) scanf("%lld%lld", &x[i], &y[i]);
    int ans = n;
    rep(i, n)For(j, i+1, n){
        lint p = x[j]-x[i], q = y[j]-y[i];
        int tmp = n;
        rep(k, n)For(l, k+1, n){
            tmp -= ((x[k]+p == x[l] && y[k]+q == y[l]) || (x[k]-p == x[l] && y[k]-q == y[l]));
        }
        chmin(ans, tmp);
    }
    printf("%d\n", ans);
}