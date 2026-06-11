/*
 * @Autor: valk
 * @Date: 2020-07-17 16:50:40
 * @LastEditTime: 2020-09-19 20:32:30
 * @Description: 如果邪恶  是华丽残酷的乐章 它的终场 我会亲手写上 晨曦的光 风干最后一行忧伤 黑色的墨 染上安详
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#define emplace_back push_back
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9 + 7;
const int seed = 12289;
const double eps = 1e-6;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 10;

int fa[N], sz[N];

int find(int x){
    if(fa[x]==x)
        return x;
    return fa[x] = find(fa[x]);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        sz[i] = 1;
    }
    int ans = 1;
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        int uu = find(u), vv = find(v);
        if (uu == vv)
            continue;
        fa[uu] = vv;
        ans = max(ans, sz[vv]+=sz[uu]);
    }
    printf("%d\n", ans);
    return 0;
}