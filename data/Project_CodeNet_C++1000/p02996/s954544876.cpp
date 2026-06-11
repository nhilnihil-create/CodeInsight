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
    vector<pair<int, int>> tasks;
    int a, b;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        tasks.emplace_back(b, a);
    }
    sort(tasks.begin(), tasks.end());
    int sum = 0;
    for (auto i : tasks)
    {
        sum += i.second;
        if (sum > i.first)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
