#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
vector<ll> fac, finv, inv;


int main(){
    int n;  cin >> n;
    vector<ll> a(n);
    REP(i, n)   cin >> a.at(i);
    sort(ALL(a));

    ll res=0;
    REP(i, 61){
        ll cnt0=0, cnt1=0;
        REP(j, n){
            if(a[j]& 1LL<<i) cnt1 += 1;
            else cnt0 += 1;
        }
        ll tmp = (1LL<<i)%MOD;
        res += tmp*(cnt1*cnt0%MOD);
        res %= MOD;
    }
    cout << res << endl;

}