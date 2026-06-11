#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    int n;
    string s, tmp1, tmp2;
    cin >> s;

    tmp1=s;
    tmp2=s;
    reverse(tmp1.begin(), tmp1.end());
    if (s.compare(tmp1) != 0)
    {
        cout << "No" << endl;
        return 0;
    }

    // cout << s.substr(0, (s.length() - 1) / 2) << endl;
    tmp1 = s.substr(0, (s.length() - 1) / 2);
    tmp2 = s.substr(0, (s.length() - 1) / 2);
    reverse(tmp2.begin(), tmp2.end());
    // cout << tmp1 << " " << tmp2 << endl;
    if (tmp1.compare(tmp2) != 0)
    {
        cout << "No" << endl;
        return 0;
    }
    tmp1 = s.substr((s.length() + 1) / 2, (s.length() - 1) / 2);
    tmp2 = s.substr((s.length() + 1) / 2, (s.length() - 1) / 2);
    reverse(tmp2.begin(), tmp2.end());
    // cout << tmp1 << " " << tmp2 << endl;
    if (tmp1.compare(tmp2) != 0)
    {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    return 0;
}