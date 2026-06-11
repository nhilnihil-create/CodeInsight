#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
int n;
long long res;
string s;
unordered_map<string, int> m;
int main() {
    DAU
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        sort(s.begin(), s.end());
        ++m[s];
    }
    for (const auto& P : m)
        res += 1LL * P.second * (P.second - 1) / 2LL;
    cout << res;
    PLEC
}
