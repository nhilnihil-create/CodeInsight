#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    map<string, int> table;
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        ++table[s];
    }
    int m = 0;
    for (auto i : table)
        if (m < i.second)
            m = i.second;
    for (auto i : table)
        if (i.second == m)
            cout << i.first << endl;
}