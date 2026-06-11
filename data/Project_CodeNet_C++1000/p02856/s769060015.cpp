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

vector<lint> table[10];
void init(int d){
    lint x = d * 2; lint m = 0, c = 0;
    if(x > 9){
        x -= 9; c++;
    }
    while(x != d){
        table[d].push_back(c);
        x += d;
        if(x > 9){
            x -= 9; c++;
        }
    }
    table[d].push_back(c);
}

int main(){
    rep(d, 10) init(d);

    ii(M);
    lint res = 0; vector<lint> vec;
    rep(i, M){
        lint d, c; cin >> d >> c;
        if(c > 1){
            res += c - 1;
            lint s = table[d].size();
            lint p = table[d][(c-2) % s], q = table[d].back();
            res += ((c - 2) / s) * q + p;
        }
        lint t = d * c;
        while(t > 9){
            lint s = 0;
            while(t > 0){
                s += (t % 10); t /= 10;
            }
            t = s;
        }
        vec.push_back(t);
    }
    
    rep(i, M - 1){
        if(vec[i] + vec[i+1] > 9){
            res++;
            vec[i+1] -= 9;
        }
        res++; vec[i+1] += vec[i];
    }
    out(res);
}