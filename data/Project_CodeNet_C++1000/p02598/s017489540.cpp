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

vector<ll> a;
ll n, k;
bool chk(ll x){
    ll sum=0;
    rep(i, n)   sum += (a[i]-1)/x;
    return sum<=k;
}
int main(){
    cin >> n >> k;
    a.resize(n);
    ll lb=0, ub=LINF;
    rep(i, n) cin >> a[i];
    while(1<ub-lb){
        ll mid = (lb+ub)/2;
        if(chk(mid)) ub = mid;
        else lb = mid;
        //cout << lb << ' ' << ub << endl;
    }
    cout << ub << endl;
}
