#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main() {
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;
    for (int i = 0; i < (int)s.size() - 2; ++i) {
        if (s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') ++ans;
    }
    cout << ans << endl;
}
