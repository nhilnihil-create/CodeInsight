#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s;
    cin >> s;

    int n = s.size();
    bool isEasy = true;
    rep (i, n)
        if (((i + 1) % 2 == 1 && s[i] == 'L') || (i + 1) % 2 == 0 && s[i] == 'R')
            isEasy = false;

    if (isEasy)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}