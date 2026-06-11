#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(m);
    vector<ll> dp(n+1, -1);  
    for(int i=0; i<m; ++i){
        cin >> a[i]; dp[a[i]] = 0;
    }
    for(int i=0; i<m-1; ++i){
        for(int j=i+1; j<m; ++j){
            if(abs(a[i]-a[j])==1){
                cout << 0 << endl; return 0;
            }
        }
    }
    dp[0] = 1; dp[1] = 1;
    for(int i=0; i<m; ++i){
        if(a[i]==1){dp[1]=0;}
    }
    for(int i=0; i<n-1; ++i){
        if(dp[i+2]==0){continue;}
        dp[i+2] = (dp[i+1] + dp[i])%mod;
    }
    cout << dp[n] << endl;
    return 0;
}