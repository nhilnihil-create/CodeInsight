#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
/////////////////////////////////
int main()
{
    string s;
    cin >> s;
    if (s[0] == s[1] && s[2] == s[3] && s[0] != s[3])
        cout << "Yes" << endl;
    else if (s[0] == s[2] && s[1] == s[3] && s[0] != s[1])
        cout << "Yes" << endl;
    else if (s[0] == s[3] && s[1] == s[2] && s[0] != s[1])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}