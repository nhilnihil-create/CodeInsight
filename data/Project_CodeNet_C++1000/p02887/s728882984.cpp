#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    string s;
    cin >> n >> s;

    int ans = 1;
    char pre = s[0];
    for (size_t i = 1; i < n; i++) {
        if (s[i] != pre) {
            ans++;
            pre = s[i];
        }
    }

    cout << ans << endl;
    return 0;
}
