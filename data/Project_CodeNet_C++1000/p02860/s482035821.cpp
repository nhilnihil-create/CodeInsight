#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    rep(i, n / 2) t += s[i];
    t += t;
    if (s == t)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}