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

const ll mod = 1000000007;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int dp[n][n];
    rep(i, n)rep(j, n) dp[i][j] = 0;
    rep(i, n-1){
        if(s[i] == s[n-1]) dp[i][n-1] = 1;
        else dp[i][n-1] = 0;
    }
    int ans = 0;
    for (int j = n - 2; j >= 1; j--){
        for (int i = j - 1; i >= 0; i--){
            if(s[i] == s[j]){
                dp[i][j] = min(dp[i+1][j+1] + 1, j - i);
                ans = max(dp[i][j], ans);
            }else{
                dp[i][j] = 0;
            }
        }
    }
    // rep(i, n){
    //     rep(j, n){
    //         cout << dp[i][j] << " ";
    //     }cout << endl;
    // }

    cout << ans << endl;
}