#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define COUT(x) cout<<(x)<<"\n"

int main(){
    int h,n;
    cin >> h >> n;
    vector<int> a(n),b(n);
    REP(i,n){
        cin >> a[i] >> b[i];
    }
    vector<int> dp(20050,1e9);
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
