#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[10];
    cin >> s;
    bool flag = true;
    if (s[2] != s[3] || s[4] != s[5])
    {
        flag = false;
    }
    if (flag == true)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}