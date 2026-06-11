#include<bits/stdc++.h>
/* #define int long long */
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

signed main(){
    double w, h, x, y;
    cin >> w >> h >> x >> y;
    ll rect = w * h;
    long double ans = rect / 2.0;
    int res;
    if(x == w / 2.0 && y == h / 2.0) res = 1;
    else res = 0;

    printf("%.10Lf %d\n", ans, res);
}