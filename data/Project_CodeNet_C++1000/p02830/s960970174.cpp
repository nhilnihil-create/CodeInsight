#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    string ans;
    for (size_t i = 0; i < n; i++) {
        ans += s[i];
        ans += t[i];
    }

    cout << ans << endl;
    return 0;
}
