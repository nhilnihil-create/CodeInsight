#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    string s;
    cin >> s;

    bool flag = false;
    rep(i, s.size()) {
        if (s[i] == '7')
            flag = true;
    }

    flag ? cout << "Yes" : cout << "No";
    cout << endl;

    return 0;
}
