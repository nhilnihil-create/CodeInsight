
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

//dp動的計画法の問題
//dp[i]=dp[i+1]+dp[i+2]という漸化式で表せる
int main(){
    int n, m;
    cin >> n >> m;
    //壊れた段に1、壊れてない段は0
    vector<int> broken(n+1);
    rep(i,m){
        int a;
        cin >> a;
        broken[a]=1;
    }
    vector<int> dp(n+2);
    const int mod=1000000007;
    dp[n]=1; //初期値
    for(int i=n-1; i>=0; i--){
        if(broken[i]){
            dp[i]=0;
            continue;
        }
        dp[i]=(dp[i+1]+dp[i+2]) %mod;
    }
    cout << dp[0] << endl;
    return 0;

}