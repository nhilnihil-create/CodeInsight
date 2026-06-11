#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define rrep(i,x,y) for(ll i=(ll)(y)-1;i>=(x);i--)
#define all(x) (x).begin(),(x).end()
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
#define itrdebug(x) cerr << #x << " "; for (auto & el : (x)) {cerr << (el) << " ";} cerr << endl
#define dassert(...) assert(__VA_ARGS__)
#else
#define debug(x)
#define itrdebug(x)
#define dassert(...)
#endif
//#define int long long

typedef long long ll;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-8;

void solve(long long a, long long b, long long c){
    // a + b + 2(ab)^0.5 < c
    // 2(ab)^0.5 < c - a - b
    // => c - a - b > 0 && 4ab < (c-a-b)^2

    bool yes = c-a-b > 0 && 4*a*b < (c-a-b)*(c-a-b);
    cout << (yes ? "Yes" : "No") << endl;
}

signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    long long a;
    scanf("%lld",&a);
    long long b;
    scanf("%lld",&b);
    long long c;
    scanf("%lld",&c);
    solve(a, b, c);
    return 0;
}
