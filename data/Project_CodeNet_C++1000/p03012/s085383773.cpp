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
    int N;
    cin >> N;

    int W[N], S[N], temp = 0;
    REP(i, N){
        cin >> W[i];
        temp += W[i];
        S[i] = temp;
    }

    int ans = 1e+9;
    REP(i, N){
        ans = min(ans, abs(S[N-1] - 2*S[i]));
    }

    cout << ans << endl;

    return 0;
}