#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    deque<char> dS(s.size());
    for (int i = 0; i < s.size(); i++) dS[i] = s[i];

    int Q;
    cin >> Q;

    int rev = 0;

    for (int i = 0; i < Q; i++)
    {
        int t;
        cin >> t;
        if (t == 2)
        {
            int f;
            char c;
            cin >> f >> c;
            --f;
            if (rev) f = 1 - f;
            if (f == 0)
            {
                dS.push_front(c);
            }
            else
            {
                dS.push_back(c);
            }
        }
        else
        {
            rev = 1 - rev;
        }
    }
    if (rev) reverse(dS.begin(), dS.end());
    for (auto c : dS) cout << c;
    cout << endl;

    return 0;
}
