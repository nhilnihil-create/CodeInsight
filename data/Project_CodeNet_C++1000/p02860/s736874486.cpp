#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n; string s;
    cin >> n >> s;
    if (n & 1) cout << "No\n";
    else {
        int len = n / 2;
        cout << (s.substr(0,len)==s.substr(n/2,len) ? "Yes" : "No") << '\n';
    }
    return 0;
}