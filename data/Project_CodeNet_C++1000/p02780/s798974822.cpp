#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)
int main(void)
{
    int N, K;
    cin >> N >> K;
    double p[N];
    double E[N + 1];
    for (int i = 0; i < N; i++)
    {
        cin >> p[i];
    }
    fill(E, E + N + 1, 0.0);
    double tmp = 0.0;
    for (int i = 1; i <= N; i++)
    {
        tmp = (1.0 + p[i - 1]) / 2.0;
        E[i] = E[i - 1] + tmp;
        tmp = 0;
    }
    double ans = -1.0;
    for (int i = 0; i <= N - K; i++)
    {
        ans = max(ans, E[i + K] - E[i]);
    }
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}
