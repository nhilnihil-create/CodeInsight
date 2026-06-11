#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size(), ans = 0;
    for(int i = 0; i < n / 2; i++) {
        ans += s[i] != s[n - i - 1];
    }
    cout << ans << endl;
    return 0;
}