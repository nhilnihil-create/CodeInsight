#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for (size_t i = 0; i < 3; i++) {
        if (s[i] == t[i]) ++ans;
    }

    cout << ans << endl;
    return 0;
}
