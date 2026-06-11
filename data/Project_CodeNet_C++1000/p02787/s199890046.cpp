#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using pint = pair<int, int>;
using pll = pair<ll,ll>;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define COUT(x) cout<<(x)<<"\n"

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,n;
    cin >> h >> n;
    vector<int> a(n),b(n);
    REP(i,n){
        cin >> a[i] >> b[i];
    }
    vector<int> dp(20050,INF);
    dp[0]=0;
    for(int i=0;i<20050;i++){
        REP(j,n){
            int tes = min(h,i+a[j]);
            dp[tes]=min(dp[i]+b[j],dp[tes]);
        }
    }
    COUT(dp[h]);
    return 0;
}