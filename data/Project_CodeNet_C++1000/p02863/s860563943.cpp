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

int MAX_N = 3010;
int MAX_T = 3010;

mat dp(MAX_N, vec(MAX_T, 0));

int main(){
    int n, t;
    cin >> n >> t;
    P a[n];
    rep(i, n) cin >> a[i].first >> a[i].second;
    sort(a, a + n);
    rep(i, n){
        rep(j, t){
            if(j >= a[i].first){
                dp[i+1][j] = max(dp[i][j-a[i].first]+a[i].second, dp[i][j]);
            }else{
                dp[i+1][j] = dp[i][j];
            }
        }
    }
    int ans = 0;
    rep(i, n){
        ans = max(dp[i][t-1] + a[i].second, ans);
    }
    // rep(i, n+1){
    //     rep(j, t){
    //         cout << dp[i][j] << " ";
    //     }cout << endl;
    // }
    cout << ans << endl;
}