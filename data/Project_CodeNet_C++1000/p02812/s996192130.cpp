#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = "ABC";
    int j = 0;
    int ans = 0;
    rep(i, n) {
        if (s[i] ==  t[j]) {
            j++;
        } else if (s[i] == t[0]) {
            j = 1;
        } else {
            j = 0;
        }
        if (j == 3) {
            ans++;
            j = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
