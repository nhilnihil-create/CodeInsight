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
const int INF = 1000000000;

int main(){
    int n, m;
    cin >> n >> m;
    int a[m];
    int c[m];
    fill(c, c + m, 0);
    rep(i, m){
        int b;
        cin >> a[i] >> b;
        rep(j, b){
            int d;
            cin >> d;
            d--;
            c[i] += (1 << d);
        }
    }

    int dp[m+1][1<<n];
    rep(i, m+1)rep(j, 1<<n) dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i, m){
        rep(j, 1<<n){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            dp[i+1][j|c[i]] = min(dp[i+1][j|c[i]],min(dp[i][j|c[i]], dp[i][j] + a[i]));
        }
    }
    // rep(i, m+1){
    //     rep(j, 1<<n){
    //         cout << dp[i][j] << " ";
    //     }cout << endl;   
    // }
    if(dp[m][(1<<n)-1] == INF){
        cout << -1 << endl;
    }else{
        cout << dp[m][(1<<n)-1] << endl;
    }
}