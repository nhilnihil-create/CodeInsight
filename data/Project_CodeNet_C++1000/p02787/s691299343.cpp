#include<bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int h,n;
    cin >> h >> n;
    
    vector<int> dp(h+1,1e8);
    dp[0]=0;
    
    for (int i=0; i<n;++i) {
        int a,b;
        cin >> a >> b;
        
        for (int idx=0; idx<h+1; idx++) {
            if (dp[idx]!=1e8) {
                dp[min(idx+a,h)]=min(dp[idx]+b,dp[min(idx+a,h)]);
            }
        }
    }
    
    cout << dp[h] << endl;
    
}
