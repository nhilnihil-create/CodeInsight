#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1'000'000'007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


class FactorialMod{
    void calc_inverse(){
        inverse[0] = 0;
        inverse[1] = 1;
        for(int i=2; i<=max_num; i++){
            inverse[i] = MOD-((MOD/i)*inverse[MOD%i]%MOD);
        }
    }

    void calc_factorial_inverse(){
        factorial[0] = factorial_inverse[0] = 1;
        for (int i=1; i<=max_num; i++) {
            factorial[i] = (factorial[i-1]*i)%MOD;
            factorial_inverse[i] = (factorial_inverse[i-1]*inverse[i])%MOD;
        }
    }

    public:
        int max_num;
        vector<ll> inverse; 
        vector<ll> factorial;
        vector<ll> factorial_inverse;
        FactorialMod(int _max_num){
            max_num = _max_num;
            inverse = vector<ll>(max_num+1);
            factorial = vector<ll>(max_num+1);
            factorial_inverse = vector<ll>(max_num+1);
            calc_inverse();
            calc_factorial_inverse();
        }

        ll combination(int n, int k){
            return (((factorial[n]*factorial_inverse[k])%MOD)*factorial_inverse[n-k])%MOD;
        }

        ll multiChoose(int n, int k){
            return combination(n+k-1, k);
        }
};

int main(){
    int x, y;   cin >> x >> y;
    //重複組み合わせは配列倍(n+k)にする
    FactorialMod calc_mod(x+y);
    ll res=0;
    for(int i=0; i<=x; i++){
        ll cost = (x-i)/2;
        if(i+2*cost==x && cost+2*i==y){
            res = calc_mod.combination(i+cost, cost);
        }else if(x<i+2*cost && y<cost+2*i) break;
    }
    cout << res << endl;
}