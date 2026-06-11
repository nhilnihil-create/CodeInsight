#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#define int long long
#define lowbit(x) (x &(-x))
#define me(ar) memset(ar, 0, sizeof ar)
#define mem(ar,num) memset(ar, num, sizeof ar)
#define rp(i, n) for(int i = 0, i < n; i ++)
#define rep(i, a, n) for(int i = a; i <= n; i ++)
#define pre(i, n, a) for(int i = n; i >= a; i --)
#define IOS ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int way[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int  INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
const double EXP = 1e-8;
const ll   MOD = 1e9 + 7;
const int  N = 2e5 + 5;
int h, w;
char mp[105][105];
int dp[105][105];
signed main()
{
    IOS;
    cin >> h >> w;
    for(int i = 1; i <= h; i ++)
        for(int j = 1; j <= w; j ++)
            cin >> mp[i][j];
    if(mp[1][1] == '#') dp[1][1] = 1;
    for(int i = 1; i <= h; i ++){
        for(int j = 1; j <= w; j ++){
            if(i == 1 && j == 1) continue;
            dp[i][j] = INF;
            if(i > 1) dp[i][j] = min(dp[i][j], dp[i - 1][j] + (mp[i][j] == '#' && mp[i - 1][j] == '.'));
            if(j > 1) dp[i][j] = min(dp[i][j], dp[i][j - 1] + (mp[i][j] == '#' && mp[i][j - 1] == '.'));
        }
    }
    cout << dp[h][w] << endl;
    return 0;
}
