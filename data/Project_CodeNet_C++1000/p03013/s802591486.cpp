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
int mod = 1000000007;

//Typical DP

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> broken(N+1);
    REP(i, M){
        int a;
        cin >> a;
        broken[a] = 1;
    }

    vector<int> dp(N+2);
    dp[N] = 1;

    FORD(i, N-1, 0){
        if(broken[i]){
            dp[i] = 0;
            continue;
        }
        dp[i] = (dp[i+1] + dp[i+2]) % mod;
    }

    cout << dp[0] << endl;

    return 0;
}