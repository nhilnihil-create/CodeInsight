#include <bits/stdc++.h>
using namespace std;
int i, k = 1, p, t, a[2040];
string s;
main()
{
    for (cin >> s, i = s.size(); i--; k = k * 10 % 2019)
        a[p = (p + k * (s[i] - 48)) % 2019]++;
    for (t = *a; ++i < 2019;)
        t += a[i]-- * a[i] / 2;
    cout << t;
}
