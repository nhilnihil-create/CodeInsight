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
    string s, t;
    map<string, lli> x;
    lli cnt = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        sort(s.begin(), s.end());
        if (x[s] != 0)
        {
            cnt += x[s];
        }
        x[s]++;
    }
    cout << cnt << endl;
    return 0;
}
