#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    string s;
    cin >> s;

    int ans = 0;
    for (size_t i = 0; i < s.size()/2; i++) {
        if (s[i] != s[s.size()-i-1]) ans++;
    }

    cout << ans << endl;
    return 0;
}
