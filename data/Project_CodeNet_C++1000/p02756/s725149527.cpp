#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

//read question carefully!

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //   cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int q;
        cin >> q;
        string f = "", b = "";

        int cur = 0;
        while (q--)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                cur ^= 1;
            }
            else
            {
                int y;
                cin >> y;
                char ch;
                cin >> ch;
                y--;
                if (y ^ cur)
                {
                    b += ch;
                }
                else
                {
                    f += ch;
                }
            }
        }
        if (cur)
        {
            swap(f, b);
            reverse(s.begin(), s.end());
        }
        reverse(f.begin(), f.end());
        cout << f << s << b << "\n";
    }
}