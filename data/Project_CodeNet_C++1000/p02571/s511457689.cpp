#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, c;
    cin >> s >> c;
    int ans = 2000;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i <= s.size()-c.size(); i++)
    {
        cnt1 = 0;
        for (int j = 0, k = i; j < c.size() && k < s.size(); j++, k++)
        {
            if (s[k] != c[j])
            {
                cnt1++;
            }
        }
        ans = min(cnt1, ans);
    }

    cout << ans;
    return 0;
}