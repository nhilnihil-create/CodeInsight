/*
 * @Autor: valk
 * @Date: 2020-07-17 16:50:40
 * @LastEditTime: 2020-09-19 21:21:45
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
const int N = 1e6 + 10;

vector<int> vec[N], pos[N];
int arr[N];
int __gcd(int x, int y)
{
    if (x % y == 0)
        return y;
    return __gcd(y, x % y);
}

int vis[N], pri[N], tot;
void solve(int n)
{
    for (int i = 2; i <= n; i++) {
        if (!vis[i])
            pri[++tot] = i;
        for (int j = 1; j <= tot; j++) {
            if (i * pri[j] > n)
                break;
            vis[i * pri[j]] = pri[j]; //纪录最小的素因子
            if (i % pri[j] == 0)
                break;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    solve(1000010);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    int flag = 1;
    for (int i = n; i; i--) {
        int temp = arr[i];
        int sign = 1;
        for (int j = 2; j * j <= temp; j++) {
            if (temp % j == 0) {
                pos[j].pb(i);
                if (pos[j].size() != 1) {
                    sign = 0;
                    break;
                }
                while (temp % j == 0) {
                    temp /= j;
                }
            }
        }
        if (temp > 1) {
            pos[temp].pb(i);
            if (pos[temp].size() != 1) {
                sign = 0;
            }
        }
        if (sign == 0) {
            flag = 0;
            break;
        }
    }
    int gcd = arr[1];
    for (int i = 1; i <= n; i++) {
        gcd = __gcd(gcd, arr[i]);
    }
    if (flag == 0 && gcd == 1) {
        puts("setwise coprime");
    } else if (flag == 1) {
        puts("pairwise coprime");
    } else {
        puts("not coprime");
    }
    return 0;
}