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
    if(__builtin_popcount(n) == 1) puts("No");
    else{
        vector<pii> ans = {{1+n, 2+n}, {2+n, 3}, {3, 1}, {1, 2}, {2, 3+n}};
        for(int i=5; i<=n; i+=2){
            ans.emplace_back(i, i-1);
            ans.emplace_back(1, i);
            ans.emplace_back(i-1+n, i+n);
            ans.emplace_back(1, i-1+n);
        }
        if(n%2 == 0){
            int t = 1<<(31-__builtin_clz(n));
            ans.emplace_back(t+n, n);
            ans.emplace_back(n^1^t, n+n);
        }
        puts("Yes");
        for(auto p: ans) printf("%d %d\n", p.fi, p.se);
    }
}