#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define ll long long
#define mst(a) memset(a, 0, sizeof a)

const int mod = 1e9+7;
const int maxn = 2e5+50;
const int inf = 1e9;

vector<int> g[maxn];
int a[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int tmp = 0;
    long long sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < g[i].size(); ++j)
        {
            int to = g[i][j];
            if (to < i) cnt ++;
        }
        tmp -= cnt - 1;
        a[i] = tmp;
        sum += tmp;
    }
    long long ans = sum;
    //printf("%lld\n", sum);
    for (int i = 1; i <= n; ++i)
    {
        vector<int> nei;
        nei.push_back(i);
        nei.push_back(n+1);
        for (int j = 0; j < g[i].size(); ++j)
        {
            int v = g[i][j];
            if (v > i) nei.push_back(v);
        }
        sort(nei.begin(), nei.end());
        for (int j = 1; j < nei.size(); ++j)
        {
            sum += (j - 2) * (nei[j] - nei[j-1]);
        }
        ans += sum;
        //printf("%lld\n", sum);
    }
    cout << ans << endl;
    return 0;
}