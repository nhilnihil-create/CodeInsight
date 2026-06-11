#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    bool flag = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != t[i])
        {
            flag = false;
            break;
        }
    }
    if (flag == true)
    {
        cout << "Yes" << endl;
        return 0;
    }
    else
    {
        cout << "No" << endl;
        return 0;
    }
}