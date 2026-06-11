#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    string s;
    cin >> s;

    if (s[0] == s[1] && s[2] == s[3] && s[0] != s[2])
    {
        cout << "Yes" << '\n';
    }
    else if (s[0] == s[2] && s[1] == s[3] && s[0] != s[1])
    {
        cout << "Yes" << '\n';
    }
    else if (s[0] == s[3] && s[1] == s[2] && s[0] != s[1])
    {
        cout << "Yes" << '\n';
    }
    else
    {
        cout << "No" << '\n';
    }
    return 0;
}
