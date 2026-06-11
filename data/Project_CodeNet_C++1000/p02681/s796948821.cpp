//time:
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    bool ans = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != t.at(i))
        {
            ans = false;
        }
    }
    if (ans)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}