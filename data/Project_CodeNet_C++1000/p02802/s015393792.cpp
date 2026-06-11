#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<bool> ac(n + 1, 0);
    map<int, int> wa;
    int cwa = 0, cac = 0;
    for (int i = 0; i < m; i++)
    {
        int t;
        string s;
        cin >> t >> s;
        if (!ac[t] && s == "AC")
        {
            ac[t] = 1;
            cac++;
        }
        else if (!ac[t])
            wa[t]++;
    }
    for (auto x : wa)
    {
        if (ac[x.first])
            cwa += x.second;
    }
    cout << cac << " " << cwa << endl;
}
