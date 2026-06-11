#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n, ans = 0;
    cin >> n;
    string str;
    for (int i = 1; i <= n; ++i) {
        str = to_string(i);
        if (str.length() % 2 == 1) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}