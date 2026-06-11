#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
////////////////////////////////////////////////
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    rep(i, n)
    {
        if ((i + 1) % 2 == 0 && s[i] == 'R')
        {
            cout << "No" << endl;
            break;
        }
        if ((i + 1) % 2 == 1 && s[i] == 'L')
        {
            cout << "No" << endl;
            break;
        }
        if (i == n - 1)
            cout << "Yes" << endl;
    }
}