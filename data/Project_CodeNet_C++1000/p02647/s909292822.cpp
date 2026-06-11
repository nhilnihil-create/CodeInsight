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
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ll n, k;    cin >> n >> k;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];

    while(0<k--){
        vector<ll> work = a;
        a = vector<ll>(n, 0);
        REP(i, n){
            ll st=max(0LL, i-work[i]);
            ll ed=min(i+work[i], n)+1;
            a[st] += 1;
            if(ed<n) a[ed] -= 1;
        }
        bool flag=true;
        REP(i, n){
            if(i<n-1) a[i+1] += a[i];
            if(a[i]<n) flag = false;
        }
        if(flag) break;
    }
    REP(i, n)   cout << a[i] << ' ';

}
