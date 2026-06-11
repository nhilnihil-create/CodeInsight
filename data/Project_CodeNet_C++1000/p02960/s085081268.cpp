#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long
string S;
int dp[100010][13];

int calc(int x, int num) {
    if(x >= S.length()){
        if(num == 5) return dp[x][num] = 1;
         return dp[x][num] = 0;
    } 
    else if(dp[x][num] != -1) return dp[x][num];
    int k = S[x] - '0';
    if(S[x] != '?')  return dp[x][num] = calc(x + 1, ((num * 10) + k)% 13);
    int ret = 0;
    rep(i, 10) ret = (ret + calc(x + 1, (num * 10 + i) % 13)) % mod;
    return dp[x][num] = ret;
}


signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> S;
    rep(i, 100010) rep(j, 13) dp[i][j] = -1;
    cout << calc(0, 0) << endl;

    return 0;
}
