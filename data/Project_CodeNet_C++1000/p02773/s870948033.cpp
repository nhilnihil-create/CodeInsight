#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

//read question carefully!

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        map<string, int> mp;
        for (int i = 0; i < n; ++i)
        {
            cin >> s;
            mp[s]++;
        }
        int ma = 0;
        for (auto &i : mp)
            ma = max(ma, i.second);
        for (auto &i : mp)
        {
            if (ma == i.second)
                cout << i.first << "\n";
        }
    }
}