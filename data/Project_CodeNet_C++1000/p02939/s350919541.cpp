#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    ll cnt = 0;
    string pre, cur;
    for (int i = 0; i < n; i++) {
        cur += s[i];
        if (pre != cur) {
            pre = cur;
            cur = "";
            cnt++;
        }
    }
    cout << cnt << endl;
}