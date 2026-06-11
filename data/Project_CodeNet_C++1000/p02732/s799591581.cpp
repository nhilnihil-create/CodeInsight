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
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    lli cnt[N + 1];
    fill(cnt, cnt + N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        cnt[a[i]]++;
    }
    lli tmp = 0;
    lli total = 0;
    for (int i = 0; i <= N; i++)
    {
        total += (cnt[i] * (cnt[i] - 1)) / 2;
    }
    for (int i = 0; i < N; i++)
    {
        tmp = total;
        tmp -= (cnt[a[i]] * (cnt[a[i]] - 1)) / 2;
        tmp += ((cnt[a[i]] - 1) * (cnt[a[i]] - 2)) / 2;
        cout << tmp << endl;
    }
    return 0;
}
