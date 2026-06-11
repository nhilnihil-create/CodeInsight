/*
 * @Autor: valk
 * @Date: 2020-04-04 14:56:12
 * @LastEditTime: 2020-09-17 16:53:43
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

ll qpow(ll a, ll b)
{
    ll ans = 1;
    a %= mod;
    while (b) {
        if (b & 1) {
            ans = (ans * a) % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return ans % mod;
}

int main()
{
    ll n;
    scanf("%lld", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    ll ans = (qpow(10, n) - qpow(9, n) + mod - qpow(9, n) + mod + qpow(8, n)) % mod;
    printf("%lld\n", ans);
    return 0;
}