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
    int s;
    s = a[0];
    for (int i = 1; i < N; i++)
    {
        s ^= a[i];
    }
    int tmp = 0;
    for (int i = 0; i < N; i++)
    {
        tmp = a[i] ^ s;
        cout << tmp;
        cout << " ";
    }
    return 0;
}
