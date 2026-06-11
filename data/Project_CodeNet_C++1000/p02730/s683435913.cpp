#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        string s1 = s.substr(0, (n - 1) / 2);
        string s2 = s.substr((n + 1) / 2, n);
        //    cout << s1 << " " << s2 << "\n";
        if (s1 == s2)
            cout << "Yes"
                 << "\n";
        else
        {
            cout << "No"
                 << "\n";
        }
    }
}