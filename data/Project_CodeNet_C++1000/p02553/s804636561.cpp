/*
 * @Autor: valk
 * @Date: 2020-04-04 14:56:12
 * @LastEditTime: 2020-09-17 16:46:22
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
const ll inf = 0x3f3f3f3f;
const ll N = 2e5 + 10;

int main()
{
    ll a, b, c, d;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    ll maxn = max(a * c, max(a * d, max(b * c, b * d)));
    if (a <= 0 && b >= 0)
        maxn = max(maxn, 0LL);
    if (c <= 0 && d >= 0)
        maxn = max(maxn, 0LL);
    printf("%lld\n", maxn);
    return 0;
}