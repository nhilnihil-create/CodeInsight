#include <iostream>
#include<vector>
#include<algorithm>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define rng(a) a.begin(),a.end()
using ll = long long;

using namespace std;



int main() {
    int n;
    cin>>n;
    vector<int>h(n);
    rep(i,n) cin>>h[i];
    vector<int>dp(n+1);
    int ans = 0;
    int cnt = 0;
    for(int i = n-2; i >= 0; i--) {
        if(h[i]>=h[i+1]) {
            cnt++;
            dp[i] = max(dp[i+1],cnt);
        } else {
            cnt = 0;
        }
        ans = max(ans,dp[i]);
    }
    cout<<ans<<endl;

    return 0;
}
