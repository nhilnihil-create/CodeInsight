#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

bool ok(string s, int l, int r) {
    bool ac = true;
    for(int i = l; i < r - 1; i++) {
        if(s[i] == '#' && s[i + 1] == '#') ac = false;
    }
    return ac;
}

int main()
{
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    string s;
    cin >> s;
    if(c < d) {
        if(ok(s, a, c) && ok(s, b, d)) {
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
    else {
        if(!ok(s, a, c)) cout << "No" << endl;
        else {
            string ans = "No";
            for(int i = b - 1; i < d; i++) {
                if(s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.') ans = "Yes";
            }
            cout << ans << endl;
        }
    }
    return 0;
}
