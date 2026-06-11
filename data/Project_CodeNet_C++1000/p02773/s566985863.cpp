#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n, val = 0;
    cin >> n;
    unordered_map<string, int> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        m[s]++;
        val = max(val, m[s]);
    }
    vector<string> ans;
    for (auto a : m)
    {
        if (a.second == val)
        {
            ans.push_back(a.first);
        }
    }
    sort(ans.begin(), ans.end());
    for (string a : ans)
    {
        cout << a << '\n';
    }
    return 0;
}
