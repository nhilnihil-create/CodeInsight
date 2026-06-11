#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s, ans;
    cin >> n >> s;
    for (unsigned int i = 0; i < s.length(); i++) {
        int c = s.at(i) + n;
        if (c > 90) {
            c -= 26;
        }
        ans += char(c);
    }
    cout << ans << endl;
}