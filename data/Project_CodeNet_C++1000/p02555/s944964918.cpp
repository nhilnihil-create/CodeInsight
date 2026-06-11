#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (n); i++)
#define MOD 1000000007
using ll = long long;
typedef pair<int, int> P;

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1);
    dp[0]=1;
    rep(i,n){
        for(int j=0;j<=i-3;j++){
            dp[i]+=dp[j];
            dp[i]%=MOD;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}