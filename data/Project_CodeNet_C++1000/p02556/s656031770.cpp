#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=b-1; (ll)(a)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string YES[2] = {"NO", "YES"};
string yes[2] = {"No", "Yes"};


int main(){
    ll n;   cin >> n;
    vector<ll> x(n), y(n);
    ll maxm=-LINF, maxp=0-LINF, minim=LINF, minip=LINF;
    rep(i, n){
        cin >> x[i] >> y[i];
        maxp = max(maxp, x[i]+y[i]);
        minip = min(minip, x[i]+y[i]);
        maxm = max(maxm, x[i]-y[i]);
        minim = min(minim, x[i]-y[i]);
    }
    cout << max(maxp-minip, maxm-minim) << endl;
    
}