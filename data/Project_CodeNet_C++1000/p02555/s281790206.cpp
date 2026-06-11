#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD ll(1e9+7)
#define MAX_N 200005
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr<<#x<<": "<<x<<endl


ll factorial[MAX_N];
void make_factorial_tableMOD(){
    factorial[0] = 1;
    for(int i = 1; i < MAX_N; i++){
        factorial[i] = factorial[i-1]*i%MOD;
    }
}

ll bisection_powerMOD(ll x,ll y){
    if(y==0)        { return 1; }
    ll t = bisection_powerMOD(x*x%MOD,y/2);
    if(y%2==1)      { t = t*x%MOD; }
    return t;
}

ll nCrMOD(int n, int r){
    if(n<r || n<0 || r<0){return 0;}
    if(n==0){return 1;}
    ll a = factorial[n];
    ll b = a*bisection_powerMOD(factorial[r],(MOD-2))%MOD;
    ll c = b*bisection_powerMOD(factorial[n-r],MOD-2)%MOD;
    return c % MOD;
}

int main(){
    ll n;
    cin >> n;

    make_factorial_tableMOD();
    ll ans = 0;
    for(int i = 1; i*3 <= n ; i++){
        ll ex =  n - i*3;
        ans += nCrMOD(ex+i-1,i-1);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;

}
