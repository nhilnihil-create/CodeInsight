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
ll a, b, x;
bool chk(ld mid, ll op){
    //cout << a*b*b*tan(mid*PI/180.0) << '\n';
    if(op){
        return 2*x >= a*b*b*tan(mid*PI/180.0);
    }else{
        return a*a*a*tan((90-mid)*PI/180.0) >= 2*x;
    }
}

int main(){
    cin >> a >> b >> x;
    ll op=1;
    if(a*a*b<2*x){
        x = a*a*b-x;    op=0; 
    }
    ld eps=1e-15, lb=0, ub=90;
    while(eps<ub-lb){
        ld mid=(lb+ub)/2;
        if(chk(mid, op)) lb = mid;
        else ub = mid;
    }

    cout << fixed << setprecision(15) << 90-ub << endl;
}