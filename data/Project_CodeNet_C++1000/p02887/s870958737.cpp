#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    char t;
    for (int i = 0; i < s.size(); i++) {
        if (i != 0 && s[i] == t) {
            continue;
        }
        t = s[i];
        ans++;
    }

    cout << ans << endl;

    return 0;
}