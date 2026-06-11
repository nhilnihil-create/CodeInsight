#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        if (s.at(i) == t.at(i)) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}