#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

int main(){
    string l;
    cin >> l;
    ll mod = 1000000007;
    ll len = l.size();
    ll dp[2][len];
    dp[0][0] = 2;
    dp[1][0] = 1;
    rep(i, len - 1){
        if(l[i+1] == '1'){
            dp[0][i+1] = dp[0][i] * 2;
            dp[1][i+1] = dp[0][i] + dp[1][i] * 3;
        }else{
            dp[0][i+1] = dp[0][i];
            dp[1][i+1] = dp[1][i] * 3;
        }
        dp[0][i+1] %= mod;
        dp[1][i+1] %= mod;
    }
    ll ans = dp[0][len-1] + dp[1][len-1];
    ans %= mod;
    cout << ans << endl;
}