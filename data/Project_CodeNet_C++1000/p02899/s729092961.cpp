#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    set<array<int, 2>> s;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        s.insert({t, i});
    }
    for (auto a : s)
    {
        cout << a[1] << " ";
    }
}