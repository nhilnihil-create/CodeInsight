#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
/////////////////////////////////
int main()
{
    string s;
    cin >> s;
    bool ok = true;
    rep(i, 3)
    {
        if (s[i] == s[i + 1])
            ok = false;
    }
    if (ok)
        cout << "Good" << endl;
    else
        cout << "Bad" << endl;
}