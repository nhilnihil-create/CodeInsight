#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    bool flag = true;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (i&1)
        {
            if (s[i] != 'L' && s[i] != 'U' && s[i] != 'D')
            {
                flag = false;
                break;
            }
        }
        else
        {
            if (s[i] != 'R' && s[i] != 'U' && s[i] != 'D')
            {
                flag = false;
                break;
            }
        }
    }
    if (flag) cout << "Yes";
    else cout << "No";
}