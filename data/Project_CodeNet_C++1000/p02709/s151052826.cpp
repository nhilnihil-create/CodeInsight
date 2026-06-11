#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n;
    cin >> n;
    vector <ll> a(n);
    vector <vector <ll>> a2(n,vector <ll> (2));

    rep(i,n){
        cin >> a[i];
        a2[i][0]=a[i];
        a2[i][1]=i+1;
    }

    sort(a2.rbegin(),a2.rend());

    vector <vector <ll>> dp(n+1,vector <ll>(n+1,0));
    dp[1][1]=a2[0][0]*abs(a2[0][1]-n);
    dp[1][0]=a2[0][0]*abs(a2[0][1]-1);

    ll ans=0;
    ll ko1,ko2;
    rep(i,n+1){
        if(i>1){
            rep(j,i+1){
                if(j==0){
                    dp[i][j]=dp[i-1][j]+a2[i-1][0]*abs(a2[i-1][1]-(i));
                }
                else if(j==i){
                    dp[i][j]=dp[i-1][j-1]+a2[i-1][0]*abs(a2[i-1][1]-(n-i+1));
                }
                else{
                ko1=dp[i-1][j-1]+a2[i-1][0]*abs(a2[i-1][1]-(n-j+1));
                ko2=dp[i-1][j]+a2[i-1][0]*abs(a2[i-1][1]-(i-j));
                dp[i][j]=max(ko1,ko2);
                
            }
                if(i==n){
                    ans=max(ans,dp[i][j]);
                }
                //cout << i << " " << j << " " << dp[i][j] << endl;

            }
        }
    }

    //cout << dp[1][0] << endl;

    cout << ans << endl;
    

    return 0;
}