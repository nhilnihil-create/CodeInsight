#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long
#define fi first
#define se second
#define setpre(x) cout << fixed << setprecision(x)
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define out(x) cout << (x) << endl
#define outs(x) cout << (x) << " "
#define yn(x) cout << ((x)?("Yes"):("No")) << endl
#define YN(x) cout << ((x)?("YES"):("NO")) << endl
#define bit_c(x) __builtin_popcountll(x)

inline void logger(){ cout << endl; }
template<typename A, typename... B>
void logger(const A& a, const B&... b){
    cout << a << " , ";
    logger(b...);
}

typedef pair<lint, lint> P;
const lint MOD = 1000000007;
const lint MOD9 = 998244353;
const lint INF = MOD * MOD;
const int MAX = 10005;

/* ...o(^-^)o... */

int main(){
    ii(n);
    vector<lint> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));

    vector<lint> b, c; lint m = 0;
    if(a[0] >= 0){
        b.push_back(a[0]); m -= a[0];
        rep(i, n-1){
            c.push_back(a[i+1]); m += a[i+1];
        }
    }
    else if(a[n-1] <= 0){
        rep(i, n-1){
            b.push_back(a[i]); m -= a[i];
        }
        c.push_back(a[n-1]); m += a[n-1];
    }
    else{
        rep(i, n){
            if(a[i] <= 0){
                b.push_back(a[i]); m -= a[i];
            }
            else{
                c.push_back(a[i]); m += a[i];
            }
        }
    }
    out(m);

    int p = b.size(), q = c.size();
    lint tmp = b[0];
    rep(i, q-1){
        outs(tmp); outs(c[i]); out("");
        tmp -= c[i];
    }
    outs(c[q-1]); outs(tmp); out("");
    tmp = c[q-1] - tmp;
    rep(i, p-1){
        outs(tmp); outs(b[i+1]); out("");
        tmp -= b[i+1];
    }
}