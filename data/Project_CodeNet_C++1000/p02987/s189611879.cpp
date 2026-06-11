#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define Rep(i, s, n) for (int i = (int)s; i < (int)n; i++)
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    if (s[0] == s[1]) {
        if (s[2] == s[3] && s[0] != s[2]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    if (s[0] == s[2]) {
        if (s[1] == s[3] && s[0] != s[1]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    if (s[0] == s[3]) {
        if (s[1] == s[2] && s[0] != s[1]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}