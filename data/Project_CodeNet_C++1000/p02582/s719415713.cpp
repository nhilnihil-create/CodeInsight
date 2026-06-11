#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;

int main()
{
    // freopen("input01.txt", "r", stdin);
    // freopen("output01.txt", "w", stdout);
    string s;
    cin >> s;
    int i, n = s.size(), ct = 0;
    int mem[n + 1] = {0};
    if (s[0] == 'R')
        mem[0] = 1, ct = 1;
    for (i = 1; i < n; i++)
    {
        if (s[i] == 'R')
            mem[i] = mem[i - 1] + 1;

        ct = max(ct, mem[i]);
    }

    cout<<ct;
    return 0;
}