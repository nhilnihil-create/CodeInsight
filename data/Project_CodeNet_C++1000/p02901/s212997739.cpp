#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include <cassert>
#include <numeric>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

int dp[1<<12+5][1005];

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> o(m,0);
    int a[m];
    rep(i,m){
        int b;
        cin >> a[i] >> b;
        rep(j,b){
            int c;
            cin >> c;
            o[i]+=1<<(c-1);
        }
    }
    rep(i,1<<n)rep(j,m+1){
        dp[i][j]=INF;
    }
    dp[0][0]=0;
    rep(i,1<<n){
        rep(j,m){
            chmin(dp[i][j+1],dp[i][j]);
            chmin(dp[i|o[j]][j+1],dp[i][j]+a[j]);
        }
    }
    if(dp[(1<<n)-1][m]==INF)cout << -1 << endl;
    else cout << dp[(1<<n)-1][m] << endl;
}