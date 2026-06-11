#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#include<regex>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define int long long
#define rep(i , a , b) for(int i = a ; i <= b ; i ++)
#define P pair<int,int>
#define  sc(a) scanf("%lld",&a)
#define pf(a) printf("%lld ",a)
using namespace std;
int dp[10000005][3];
char a[10000005];
signed main()
{
    
    a[0] = '0';
    scanf("%s", a + 1);
    int len = strlen(a + 1);
    dp[len][0] = (a[len] - '0');
    dp[len][1] = 10 - (a[len] - '0');
    for (int i = len - 1; i >= 0; i--)
    {
        dp[i][0] = min(dp[i + 1][0] + (a[i] - '0'), dp[i + 1][1] + (a[i] - '0') + 1);
        dp[i][1] = min(dp[i + 1][0] + 10 - (a[i] - '0'), dp[i + 1][1] + 10 - (a[i] - '0' + 1));
    }
   pf(min(dp[0][0], dp[0][1]));
    return 0;
}






