#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

bool dp[30009][4][1009];

int main(void)
{
    int n, cnt = 0;
    string s;
    cin >> n >> s;
    dp[0][0][0]=true;
    rep(i,n)rep(j,4)rep(k,1000){
        if(dp[i][j][k] == false) continue;
        dp[i+1][j][k] = true;
        if(j <= 2){
            dp[i+1][j+1][k*10 + (s[i] - '0')] = true;
        }
    }
    rep(i,1000){
        if(dp[n][3][i]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}