#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pint pair<int, int>
#define plint pair<ll, ll>
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define REP(i,n) for (int i = 0; i < (n); ++i)
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main(){
    ll n,k;
    cin >> n >> k;
    ll ans = 0;
    const ll maxvalue = (1+n)*n/2;

    // k~n個選ぶ
    FOR(i,k,n+1){
        ll minsum = (1+(i-1))*(i-1)/2;
        ll maxsum = maxvalue - (1+(n-i))*(n-i)/2;
        ans += (maxsum-minsum+1)%MOD; // こまめに小さくしておく
    }
    // n+1個選ぶのは1パターン

    cout << (ans+1)%MOD << "\n";
    return 0;
}
