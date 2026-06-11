#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector < int > a(n);
    vector < int > pos;
    for (int i = 0; i < n; ++i)
    {
        char x = s[i];
        if (x == '<')
        {
            a[i] = 0;
        }
        else
        {
            a[i] = 1;
        }
    }
    int len = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i == 0 || a[i - 1] == a[i])
        {
            len++;
        }
        else
        {
            if (a[i - 1] == 0)
                pos.push_back(len);
            else
                pos.push_back(-len);
            len = 1;
        }
    }

    if (a[n - 1] == 0)
        pos.push_back(len);
    else
        pos.push_back(-len);
//    for (auto i : pos)
//        cout << i << ' ';
    int ans = 0;
    int l = 0, r = pos.size() - 1;
    if (pos[l] < 0)
    {
        pos[l] = abs(pos[l]);
        ans += pos[l] * (pos[l] + 1) / 2;
      	pos[l] = -pos[l];
        l++;
    }
    if (pos[r] > 0)
    {
        ans += pos[r] * (pos[r] + 1) / 2;
        r--;
    }
    for (int i = l; i + 1 <= r; i += 2)
    {
        int len1 = abs(pos[i]), len2 = abs(pos[i + 1]);
        int ad = max(len1, len2), bc = min(len1, len2);
        ans += ad * (ad + 1) / 2;
        ans += bc * (bc - 1) / 2;
    }
    cout << ans;
    return 0;
}
