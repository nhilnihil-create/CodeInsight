#include <bits/stdc++.h>
#define rep(i, a) for (ll i = 0; i < (a); ++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define sort_1(v) sort(v.begin(),v.end())
#define sort_2(v) sort(v.begin(),v.end(),greater<ll>())
#define reverse(v) reverse(v.begin(),v.end())
typedef long long ll;
typedef long double la;
using namespace std;

char s[101][101];
int a[101][101];
int cnt = 0;

void dfs(int y, int x){
    
}

int main(){
    int h,w;
    cin >> h >> w;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            char c;
            cin >> c;
            if(c == '.'){
                a[i][j] = 0;
            }else{
                a[i][j] = 1;
            }
        }
    }
    int dp[h+1][w+1];
    dp[1][1] = a[1][1];
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(i == 1 && j == 1) continue;
            if(i == 1) dp[i][j] = dp[i][j-1] + (a[i][j-1]?0:a[i][j]);
            else if(j == 1) dp[i][j] = dp[i-1][j] + (a[i-1][j]?0:a[i][j]);
            else dp[i][j] = min(dp[i-1][j] + (a[i-1][j]?0:a[i][j]) ,dp[i][j-1] + (a[i][j-1]?0:a[i][j]));
        }
    }
    cout << dp[h][w] << endl;
}