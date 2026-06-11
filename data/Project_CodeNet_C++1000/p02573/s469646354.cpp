#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define INF 0x3f3f3f3f
#define ONF 0xc0c0c0c0
using namespace std;
typedef long long ll;
int par[10000005], num[10000005];
void init(int n)
{
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        num[i] = 1; //这里是求最大集合的个数，如果求最后集合中权值最大为多少就让num数组初始化为最开始各个元素的权值。
    }
}
int get_par(int x)
{
    return par[x] == x ? x : par[x] = get_par(par[x]);
}
void doit(int x, int y)
{
    int dx = get_par(x);
    int dy = get_par(y);
    if (dx != dy) {
        par[dx] = dy;
        num[dy] = num[dx] + num[dy];
    }
}
int main()
{
    int n, x, y, m;
    cin >> n >> m;
    init(n);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &x, &y);
        doit(x, y);
    }
    int Max = 0;
    for (int i = 1; i <= n; i++)
        Max = max(Max, num[i]);
    cout << Max << endl;
}
