/*
 * @Autor: valk
 * @Date: 2020-04-04 14:56:12
 * @LastEditTime: 2020-09-17 20:07:08
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
// #define fuck(a, b) cout << a << ' ' << b << ' ' << endl
// #define fuck(a, b, c) cout << a << ' ' << b << ' ' << c << ' ' << endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll seed = 12289;
const double eps = 1e-6;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e3 + 10;

int main()
{
    int n;
    scanf("%d", &n);
    ll maxn1 = -inf, maxn2 = -inf, minn1 = inf, minn2 = inf;
    for (ll i = 1; i <= n; i++) {
        ll x, y;
        scanf("%lld%lld", &x, &y);
        ll sum = x + y;
        ll dis = x - y;
        maxn1 = max(maxn1, sum);
        minn1 = min(minn1, sum);
        maxn2 = max(maxn2, dis);
        minn2 = min(minn2, dis);
    }
    printf("%lld\n", max(maxn1 - minn1, maxn2 - minn2));
    return 0;
}