#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repp(i, n, m) for(int (i) = (n); (i) < (m); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long
#define ldou long double
#define fi first
#define se second
#define setpre(x) std::cout << fixed << setprecision(x)
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define out(x) cout << (x) << endl
#define outs(x) cout << (x) << " "
#define yn(x) cout << ((x)?("Yes"):("No")) << endl
#define YN(x) cout << ((x)?("YES"):("NO")) << endl
#define bit_c(x) __builtin_popcountll(x)

inline void logger(){ std::cout << " [LOGGER] " << endl; }
template<typename A, typename... B>
void logger(const A& a, const B&... b){
    cout << a << " , "; logger(b...);
}

typedef pair<lint, lint> P;
const lint MOD = 1000000007;
const lint MOD9 = 998244353;
const lint INF = MOD * MOD;
const int MAX = 300005;

/* ...o(^-^)o... */

int main(){
    int n; cin>>n;
    vector<lint> a(n);
    rep(i,n){
        cin >> a[i];
    }

    if(n%3){
        rep(i, n){
            if(a[i] != 0){
                out("No"); return 0;
            }
        }
        out("Yes"); return 0;
    }

    map<lint, int> mp;
    rep(i, n) mp[a[i]]++;
    if(mp.size() > 3){
        out("No"); return 0;
    }
    if(mp.size() == 2){
        P p = *mp.begin();
        P q = *(++mp.begin());
        if(p.se > q.se) swap(p, q);
        if(p.se!=n/3 || q.se!=2*n/3 || p.fi!=0){
            out("No"); return 0;
        }
        out("Yes"); return 0;
    }
    if(mp.size() == 1){
        P p = *mp.begin();
        if(p.fi != 0){
            out("No"); return 0;
        }
        out("Yes"); return 0;
    }

    auto itr = mp.begin();
    P p = *itr; itr++;
    P q = *itr; itr++;
    P r = *itr;
    if(p.se!=n/3 || q.se!=n/3 || r.se!=n/3){
        out("No"); return 0;
    }
    if(p.fi != (q.fi^r.fi)){
        out("No"); return 0;
    }
    out("Yes");
}