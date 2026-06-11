#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

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
        set<string> s;
        string x;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            s.insert(x);
        }
        cout << s.size() << "\n";
    }
}