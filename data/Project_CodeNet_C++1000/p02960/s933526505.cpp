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
int calc(int x, int n) {
    //cout << x << " " << n << endl;
    n %= 13;
    if (x >= S.length()) {
        if(n == 5) return 1;
        else return 0;
    }
    if (dp[x][n] != -1) return dp[x][n];
    if (S[x] != '?') {
        return dp[x][n] = calc(x + 1, n * 10 + S[x] - '0');
    }
    int sum = 0;
    rep(i, 10) {
        sum += calc(x + 1, n * 10 + i);
        sum %= mod;
    }
    return dp[x][n] = sum;
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
