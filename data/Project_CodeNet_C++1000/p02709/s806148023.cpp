#include <cstdio>
#include <stack>
#include <set>
#include <cmath>
#include <map>
#include <time.h>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <memory.h>
#include <cstdlib>
#include <queue>
#include <iomanip>
// #include <unordered_map>
#define P pair<int, int>
#define LL long long
#define LD long double
#define PLL pair<LL, LL>
#define mset(a, b) memset(a, b, sizeof(a))
#define rep(i, a, b) for (int i = a; i < b; i++)
#define PI acos(-1.0)
#define random(x) rand() % x
#define debug(x) cout << #x << " " << x << "\n"
using namespace std;
const int inf = 0x3f3f3f3f;
const LL __64inf = 0x3f3f3f3f3f3f3f3f;
#ifdef DEBUG
const int MAX = 2e3 + 50;
#else
const int MAX = 1e6 + 50;
#endif
const int mod = 1e9 + 7;

PLL a[MAX];
LL dp[2005][2005];
int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i].first);
        a[i].second = i;
    }
    sort(a+1,a+1+n, [](const PLL&x, const PLL&y){
        return x.first > y.first;
    });
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            dp[j][i-j]=max(dp[j][i-j], dp[j][i-j-1]+a[i].first*abs(a[i].second-(n-i+j+1)));
            dp[j+1][i-j-1]=max(dp[j+1][i-j-1], dp[j][i-j-1]+a[i].first*abs(a[i].second-(j+1)));
        }
    }
    LL ans = 0;
    for(int i = 0; i <= n; i++){
        ans = max(ans, dp[i][n-i]);
    }
    printf("%lld\n",ans);
}