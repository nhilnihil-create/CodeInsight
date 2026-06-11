#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
#include <stack>
#include <queue>
//#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)

//input
int main(void)
{
    lli L, R;
    cin >> L >> R;
    map<lli, lli> x;
    lli minvalue = 20000;
    for (int i = L; i < R; i++)
    {
        for (int j = i + 1; j <= R; j++)
        {
            if (i % 2019 == 0 || j % 2019 == 0)
            {
                cout << 0 << endl;
                return 0;
            }
            else
            {
                lli tmp = (i % 2019) * (j % 2019) % 2019;
                minvalue = min(minvalue, tmp);
            }
        }
    }
    cout << minvalue << endl;
    return 0;
}
