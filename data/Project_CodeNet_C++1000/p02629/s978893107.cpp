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
    vector<int> x;
    while (N > 0)
    {
        lli am = (N - 1) % 26;
        N--;
        x.push_back(am);
        N -= (am);
        N /= 26;
    }
    vector<char> moji;
    for (char c = 'a'; c <= 'z'; c++)
    {
        moji.push_back(c);
    }
    for (int i = x.size() - 1; i >= 0; i--)
    {
        cout << moji[x[i]];
    }
    cout << endl;
    return 0;
}
