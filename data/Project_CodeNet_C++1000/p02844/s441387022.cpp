#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

bool debug = 0;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int num = 0, cnt = 0;
    for (; num < 1000; ++num) {
        int ok = 0;
        string numstr = "000";
        int tmp = num;
        for (int i = 0; i < 3; ++i) {
            numstr[2 - i] = char('0' + tmp % 10);
            tmp /= 10;
        }
        for (int i = 0; i < n; ++i) {
            if (s[i] == numstr[ok]) {
                ++ok;
            }
            if (ok == 3) {
                ++cnt;
                break;
            }
        }
    }
    cout << cnt << endl;
}

int main() {
    if (debug) {
        while (true) {
            cout << "********" << endl;
            solve();
        }
    } else {
        solve();
    }
    return 0;
}