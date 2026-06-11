#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    string ans = "Yes";
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            if (s.at(i) == 'R') {
                ans = "No";
                break;
            }
        } else {
            if (s.at(i) == 'L') {
                ans = "No";
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}