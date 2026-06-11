#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<string> week = {"SAT", "FRI", "THU", "WED", "TUE", "MON", "SUN"};

    int ans = 0;
    rep(i, 7) {
        if (s == week[i]) ans = i + 1;
    }

    cout << ans << endl;
    return 0;
}
