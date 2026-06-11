#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, int> s;

    for (int i = 0; i < n; i++)
    {
        string key;
        cin >> key;
        s[key] += 1;
    }

    int maxv = 0;
    for (auto &x : s)
    {
        int v = x.second;
        if (maxv < v)
            maxv = v;
    }

    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (it->second == maxv)
        {
            cout << it->first << endl;
        }
    }
    return 0;
}