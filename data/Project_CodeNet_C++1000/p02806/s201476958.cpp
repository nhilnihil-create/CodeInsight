#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, t[50];
    cin >> n;
    string s[50], x;
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> t[i];
    }
    cin >> x;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == x) {
            for (int j = i + 1; j < n; ++j) ans += t[j];
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}
