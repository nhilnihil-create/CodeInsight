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
    lli N;
    cin >> N;
    lli tmpN = N;
    vector<lli> a;
    bool f = true;
    for (lli i = 2; i <= sqrt(N); i++)
    {
        while (N % i == 0)
        {
            if (f == true)
            {
                a.push_back(i);
            }
            f = false;
            N /= i;
        }
        f = true;
        if (N == 1)
        {
            break;
        }
    }
    if (N != 1)
    {
        a.push_back(N);
    }
    lli cnt = 0;
    if (a.size() >= 1)
    {
        lli ans = 0;
        lli div = 1;
        //lli j = 0;
        for (lli i = 0; i < a.size(); i++)
        {
            for (lli j = a[i]; j <= (lli)(pow(10, 12)); j = j * a[i])
            {
                if (tmpN == 1 || tmpN % j != 0)
                {
                    break;
                }
                else
                {
                    tmpN /= j;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    else
    {
        if (tmpN == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
    return 0;
}
