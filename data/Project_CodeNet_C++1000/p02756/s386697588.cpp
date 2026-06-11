#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define per(i, n) for (int i = (n)-1; i > -1; i--)
#define reps(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define sper(i, s, n) for (int i = (s); i >= (int)(n); i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    string s;
    cin >> s;
    int q;
    cin >> q;
    bool flip = false;
    rep(i, q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            if (!flip)
                flip = true;
            else
                flip = false;
        }
        else
        {
            int f;
            string c;
            cin >> f >> c;
            if (f == 1)
            {
                if (!flip)
                    s.insert(0, c);
                else
                    s += c;
            }
            else
            {
                if (flip)
                    s.insert(0, c);
                else
                    s += c;
            }
        }
    }
    if (flip)
        reverse(s.begin(), s.end());
    cout << s << endl;
}

int main()
{
    solve();
    return 0;
}