#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <stack>
//#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)
int main(void)
{
    int N, M, X;
    cin >> N >> M >> X;
    int C[N];
    int A[N][M];
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];
        }
    }
    int sum[M];
    int price = 0;
    int cnt = 0;
    int ans = INT32_MAX;
    for (int bit = 0; bit < (1 << N); ++bit)
    {
        fill(sum, sum + M, 0);
        price = 0;
        for (int i = 0; i < N; ++i)
        {
            if (bit & (1 << i))
            {
                price += C[i];
                for (int j = 0; j < M; j++)
                {
                    sum[j] += A[i][j];
                }
            }
        }
        bool ok = true;
        for (int k = 0; k < M; k++)
        {
            if (sum[k] < X)
            {
                ok = false;
            }
        }
        if (ok == true)
        {
            ans = min(ans, price);
        }
    }
    if (ans != INT32_MAX)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}
