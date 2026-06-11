/*
 * @Autor: valk
 * @Date: 2020-04-04 14:56:12
 * @LastEditTime: 2020-09-17 17:06:44
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
const int N = 2e3 + 10;

ll dp[N][N], sum[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 3; i <= n; i++) {
        dp[i][i] = sum[i] = 1;
    }
    for (int i = 6; i <= n; i++) {
        for (int j = 3; j <= i - 3; j++) {
            dp[i][j] += sum[i - j];
            sum[i] += dp[i][j];
            dp[i][j] %= mod;
            sum[i] %= mod;
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         printf("%lld ", dp[i][j]);
    //     }
    //     cout << endl;
    // }
    printf("%lld\n", sum[n]);
    return 0;
}