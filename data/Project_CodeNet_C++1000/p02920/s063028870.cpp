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
const int MAX = 100005;

/* ...o(^-^)o... */

int main(){
    int n; cin >> n; int v_max = 1 << n;
    vector<long> v(v_max), u;
    rep(i, v_max) cin >> v[i];
    sort(all(v), greater<long>());

    u.push_back(v[0]); v[0] = -1;
    rep(i, n){
        int m = 1 << i; int l = 0;
        rep(j, m){
            while(1){
                l++;
                if(l == v_max){
                    out("No"); return 0;
                }
                if(v[l] == -1) continue;
                if(v[l] < u[j]){
                    u.push_back(v[l]);
                    v[l] = -1;
                    break;
                }
            }
        }
        sort(all(u), greater<long>());
    }
    out("Yes");
}