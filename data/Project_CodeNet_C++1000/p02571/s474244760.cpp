#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define max 10000000
// cout << "YES\n";
// cout << "NO\n";
int main()
{
    string t, s;
    cin >> s >> t;
    int m, res = 1e5, f = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        m = 0;
        for (int j = 0; j < (int)t.size(); j++)
        {
            if (i + j >= (int)s.size())
            {
                f = 1;
                break;
            }
            if (t[j] != s[i + j])
            {
                m++;
            }
        }
        if (f == 1)
        {
            break;
        }
        res = min(res, m);
    }
    cout << res << endl;
    return 0;
}