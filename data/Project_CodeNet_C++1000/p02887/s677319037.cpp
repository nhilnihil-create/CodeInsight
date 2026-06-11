#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 1;
    string s;

    cin >> n >> s;

    for (int i = 1; i < int(s.size()); i++) {
        if (s[i] != s[i - 1]) {
            ans++;
        }
    }

    cout << ans << endl;
}

