#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    string s, t;
    cin >> s;
    t = s;
    reverse(t.begin(), t.end());
    int ans = 0;
    rep(i, s.size()) {
        if (s[i] != t[i]) ans++;
    }
    cout << ans/2 << endl;
    return 0;
}