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

int dp[100010][2];
string L; 
int calc(int x, int smaller) {
    if(x >= L.length()) return dp[x][smaller] = 1;
    if(dp[x][smaller] != -1) return dp[x][smaller];
    if(smaller) {
        return dp[x][smaller] = (calc(x + 1, smaller) * 3) % mod;
    }
    if(L[x] == '0') {
        return dp[x][smaller] = (calc(x + 1, smaller));
    }
    return dp[x][smaller] = (calc(x + 1, 0) * 2 + calc(x + 1, 1)) % mod;

}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> L;
    rep(i, 100010) rep(j, 2) dp[i][j] = -1;
    cout << calc(0, 0) << endl;

    return 0;
}
