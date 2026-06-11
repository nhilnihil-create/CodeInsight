#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
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
#define SUM(x) accumulate(ALL(x), 0LL);
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ll n;  cin >> n;
    vector<ll> a(n+1);
    ll res=1, aSum=0;
    REP(i, n+1){
        cin >> a[i];    aSum += a[i];
    }
    
    if(0<n && a[0]) res = -1;
    if(!n && 1<a[0]) res = -1;
    if(0<res){
        ll cur=1;
        FOR(i, 1, n+1){
            aSum -= a[i-1];
            cur = 2*(cur-a[i-1]);
            if(cur<a[i]){
                cout << -1 << endl;
                return 0;
            }
            //cout << aSum << ' ' << ub << ' ';
            cur = min(aSum, cur);
            res += cur;
            
            //cout << b[i] << ' ' << res << endl;
        }
    }
    cout << res << endl;
}