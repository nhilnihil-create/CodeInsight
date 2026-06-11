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
    cout << a << " , ";
    logger(b...);
}

typedef pair<lint, lint> P;
const lint MOD = 1000000007;
const lint MOD9 = 998244353;
const lint INF = MOD * MOD;
const int MAX = 5000*5000+5;

/* ...o(^-^)o... */

int n;
int id(int i){
    if(i < 0) return n+i;
    if(i >= n) return i-n;
    return i;
}

int main(){
    cin >> n;
    vector<lint> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    queue<int> que;
    rep(i, n){
        if(b[i] > a[i] && b[i]>b[id(i-1)]+b[id(i+1)]){
            que.push(i);
        }
    }

    lint res = 0;
    while(!que.empty()){
        int i = que.front(); que.pop();

        lint sur = min(b[i]-a[i], b[i]-b[id(i+1)]-b[id(i-1)]) - 1;
        lint c = sur / (b[id(i+1)]+b[id(i-1)]) + 1;
        res += c;
        b[i] -= c * (b[id(i+1)]+b[id(i-1)]);

        if(b[id(i-1)] > a[id(i-1)] && b[id(i-1)]>b[i]+b[id(i-2)]) que.push(id(i-1));
        if(b[id(i+1)] > a[id(i+1)] && b[id(i+1)]>b[i]+b[id(i+2)]) que.push(id(i+1));
    }

    bool isok = true;
    rep(i, n){
        if(a[i] != b[i]) isok = false;
    }
    if(!isok){
        out(-1); return 0;
    }
    out(res);
}