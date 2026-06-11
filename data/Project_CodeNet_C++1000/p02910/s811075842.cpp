#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    string ans = "Yes";
    for (int i = 1; i <= s.size(); i++) {
        if (i%2 != 0) {
            if (s[i-1] == 'L') ans = "No";
        }
        if (i%2 == 0) {
            if (s[i-1] == 'R') ans = "No";
        }
    }
    cout << ans << endl;
    return 0;
}