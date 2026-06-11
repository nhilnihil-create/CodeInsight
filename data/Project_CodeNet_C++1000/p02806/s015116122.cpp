#include <bits/stdc++.h>
using namespace std;

string s[233];
int t[233];
string X;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> s[i] >> t[i];
    }
    cin >> X;
    int ans = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (s[i] == X) break;
        ans += t[i];
    }
    cout << ans << '\n';
    return 0;
}