#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n; i++)
using P = pair<ll, ll>;

int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (s[1] == s[2])
        cout << "No" << endl;
    else if (s[0] == s[1] && s[2] == s[3])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}