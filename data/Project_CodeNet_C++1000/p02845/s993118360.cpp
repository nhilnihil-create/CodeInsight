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


int main(){
    int n;  cin >> n;
    vector<ll> a(4, 0);
    ll x, y, z, res=1;
    REP(i, n){
        int t, cnt=0, id=0;  cin >> t;
        if(t==a[1]){
            cnt += 1; id=1;
        } 
        if(t==a[2]){
            cnt += 1; id=2;
        } 
        if(t==a[3]){
            cnt += 1; id=3;
        } 
        if(id==0){
            cout <<  0 << endl;
            return 0;
        }
        a[id] += 1;
        res *= cnt;
        res %= MOD;
    }
    cout << res << endl;
}