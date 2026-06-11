#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sd second
#define ft first

int32_t main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    int sum = 0;
    for (auto x : mp)
    {
        sum += ((x.sd) * (x.sd - 1)) / 2;
    }
    for (auto x : a)
    {
        int m = mp[x];
        cout << sum - (m - 1) << endl;
    }
    return 0;
}