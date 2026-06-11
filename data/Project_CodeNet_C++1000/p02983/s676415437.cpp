#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

int main() {
    ll L, R;
    cin >> L >> R;

    int N;
    if(R-L >= 2019) cout << 0 << endl;
    else{
        ll ans = 1e+9;
        FOR(i, L, R-1){
            FOR(j, i+1, R){
                ans = min(ans, (i*j)%2019);
            }
        }
        cout << ans << endl;
    }

    return 0;
}