#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef pair<ll, ll> P;

P baby[2000] = {};
ll dp[2001][2001] = {};

int main(){
    ll n, i, j;
    cin >> n;
    for(i=0; i<n; i++){
        baby[i].second = i+1;
        cin >> baby[i].first;
    }
    sort(baby, baby+n, greater<P>());
    for(i=0; i<=n; i++){
        for(j=0; j<=n; j++){
            if(i == 0 && j == 0){
                dp[i][j] = 0;
            }else if(i == 0){
                dp[i][j] = dp[i][j-1]+baby[i+j-1].first*abs(baby[i+j-1].second-(j-1)-1);
            }else if(j == 0){
                dp[i][j] = dp[i-1][j]+baby[i+j-1].first*abs(n-baby[i+j-1].second-(i-1));
            }else if(i+j>n){
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }else{
                dp[i][j] = max(dp[i-1][j]+baby[i+j-1].first*abs(n-baby[i+j-1].second-(i-1)), dp[i][j-1]+baby[i+j-1].first*abs(baby[i+j-1].second-(j-1)-1));
            }
        }
    }
    cout << dp[n][n];
    return 0;
}