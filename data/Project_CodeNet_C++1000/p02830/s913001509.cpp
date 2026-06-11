#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s, t, ans;
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++) {
        ans = ans + s.at(i) + t.at(i);
    }
    cout << ans << endl;
}