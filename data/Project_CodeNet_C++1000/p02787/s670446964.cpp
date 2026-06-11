#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll h,n;
ll a[1111];
ll b[1111];

int main(){
    cin >> h >> n;
    for(ll i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }
    vector<ll> dp(h+1,1e9);
    dp[0]=0;
    for(ll i=0;i<n;i++){
        for(ll j=1;j<=h;j++){
            if(j-a[i]<=0) dp[j]=min(dp[j],b[i]);
            else if(j-a[i]>0) dp[j]=min(dp[j],dp[j-a[i]]+b[i]);
        }
    }
    cout << dp[h] << endl;
    return 0;
}  
