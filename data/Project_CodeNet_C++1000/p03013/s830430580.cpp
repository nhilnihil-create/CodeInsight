#include<bits/stdc++.h>
#define ll long long
#define boostUP ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define sz(arr) sizeof(arr)/sizeof(arr[0])
#define mod 1000000007
using namespace std;

int main(){
    boostUP;
    ll n,m;
    cin >> n >> m;

    int dp[n+1],j = 0;
    dp[0] = 1;

    if(m != 0){
        vector<int>treads(m);
        for(int i = 0; i < m; i++){
            cin >> treads[i];    
        }
        for(int i = 1; i <= n; i++){
            if(i == treads[j]){
                dp[i] = 0;
                j++;
                continue;
            }
            else{
                if(i == 1)
                    dp[i] = dp[0];
                else
                    dp[i] = (dp[i-1] + dp[i-2]) % mod;
            }
        }
    }
    else{
        dp[1] = 1;
        for(int i = 2; i <=n; i++){
            dp[i] = (dp[i-1] + dp[i-2]) % mod;
        }
    }
    // for(int i = 1; i <= n; i++)
    //     cout << dp[i] << " ";
    // cout << "\n";
    cout << dp[n] << "\n" ;
}


