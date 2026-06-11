#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <bitset>
#include <stack>
//#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
}
int main(void)
{
    //ABC153E方針:Hに到達するまでのDPテーブルを生成する
    lli H, N;
    cin >> H >> N;
    lli a[10010], b[10010];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i] >> b[i];
    }
    lli dp[10010];
    for (int i = 0; i <= H; i++)
    {
        dp[i] = 1000000000000000;
    }
    dp[0] = 0;
    for (int i = 1; i <= H; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (i > a[j])
            {
                chmin(dp[i], dp[i - a[j]] + b[j]);
            }
            else
            {
                chmin(dp[i], b[j]);
            }
        }
    }
    cout << dp[H] << endl;
    return 0;
}