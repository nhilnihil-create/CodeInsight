#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(55);
    vector<int> t(55);
    for (int i = 0; i < n; i++) {
        cin >> s.at(i) >> t.at(i);
    }
    string x;
    cin >> x;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s.at(i) == x) {
            break;
        }
        ans += t.at(i);
    }
    cout << ans << endl;
    return 0;
}
