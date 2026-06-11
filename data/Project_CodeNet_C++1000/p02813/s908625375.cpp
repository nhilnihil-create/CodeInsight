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
    int N;
    cin >> N;
    //int p[N];
    //int q[N];
    vector<int> cp, p, q;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        p.push_back(tmp);
    }
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        q.push_back(tmp);
    }
    for (int i = 0; i < N; i++)
    {
        cp.push_back(p[i]);
    }
    sort(cp.begin(), cp.end());
    int cnt1 = 0;
    do
    {
        cnt1++;
        if (cp == p)
        {
            break;
        }
    } while (next_permutation(cp.begin(), cp.end()));
    sort(cp.begin(), cp.end());
    int cnt2 = 0;
    do
    {
        cnt2++;
        if (cp == q)
        {
            break;
        }
    } while (next_permutation(cp.begin(), cp.end()));
    cout << abs(cnt1 - cnt2) << endl;
    return 0;
}
