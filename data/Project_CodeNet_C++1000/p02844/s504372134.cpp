#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < 1000; i++) {
        ostringstream oss;
        oss << setw(3) << setfill('0') << i;
        string t = oss.str();

        int p = 0;
        for (char c : s) {
            if (t[p] == c) p++;
            if (p == 3) break;
        }
        if (p == 3) ans++;
    }
    cout << ans << endl;
}