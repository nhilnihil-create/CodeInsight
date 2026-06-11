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
int main(){
    ll m;   cin >> m;
    ll sum=0, dig=0;
    REP(i, m){
        ll d, c;    cin >> d >> c;
        sum += d*c; dig += c;
    }
    cout << (sum-1)/9 + dig-1 << endl;
}