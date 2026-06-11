#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sd second
#define ft first

#define ios                           \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int32_t main()
{
    ios;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> mp, rmp;
    mp[1] = 0;
    rmp[0] = 1;
    int last = 1, i = 0, temp = k;
    bool flag = false;

    while (k != 0)
    {
        if (mp.find(a[last - 1]) == mp.end())
        {
            mp[a[last - 1]] = ++i;
            rmp[i] = a[last - 1];
            last = a[last - 1];
            k--;
        }
        else
        {
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        cout << last << endl;
    }
    else
    {
        int len = i - mp[a[last - 1]] + 1, beg = mp[a[last - 1]];
        int index = beg + (temp - beg) % len;
        if (beg == 0)
        {
            cout << rmp[temp % len] << endl;
        }
        else
        {
            cout << rmp[index] << endl;
        }
    }
    return 0;
}