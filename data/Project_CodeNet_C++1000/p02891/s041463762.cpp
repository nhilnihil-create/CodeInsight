#include <bits/stdc++.h>
using namespace std;
string s, s1;
int k;
int ans[3];
int main()
{
    while (cin >> s >> k)
    {
        s1 = s + s + s;
        for (int i = 1; i < s1.size(); i++)
        {
            if (s1[i] == s1[i - 1])
            {
                s1[i] = '.';
                ans[(i / s.size())]++;
            }
        }
        k--;
        long long res = ans[0];
        res += 1ll * (k + 1) / 2 * ans[1];
        res += 1ll * k / 2 * ans[2];
        cout << res << endl;
    }
}