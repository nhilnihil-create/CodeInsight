#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define sd second
#define ft first
#define ios                           \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int32_t main()
{
    string s;
    cin >> s;
    int q;
    cin >> q;
    bool flag = true;
    deque<char> l;
    l.push_back('.');
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            flag = !flag;
        }
        else
        {
            char f, ch;
            cin >> f >> ch;
            if (f == '1')
            {
                if (flag)
                {
                    l.push_front(ch);
                }
                else
                {
                    l.push_back(ch);
                }
            }
            else
            {
                if (flag)
                {
                    l.push_back(ch);
                }
                else
                {
                    l.push_front(ch);
                }
            }
        }
    }
    string ans;
    for (auto x : l)
    {
        if (x == '.')
        {
            ans += s;
        }
        else
        {
            ans += x;
        }
    }
    if (!flag)
    {
        reverse(ans.begin(), ans.end());
    }
    cout << ans << endl;
    return 0;
}
