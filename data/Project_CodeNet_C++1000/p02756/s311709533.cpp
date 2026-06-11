#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    int rev = 0;
    string head, tail;
    string s;
    int q;
    cin >> s >> q;
    int t, f;
    char c;
    for (int i = 0; i < q; i++) {
        cin >> t;
        if (t == 1) {
            rev++;
        } else {
            cin >> f >> c;
            if (f == 1) {
                if (rev % 2) {
                    tail += c;
                } else {
                    head += c;
                }
            } else {
                if (rev % 2) {
                    head += c;
                } else {
                    tail += c;
                }
            }
        }
    }
    string ans;
    if (rev % 2) {
        reverse(tail.begin(), tail.end());
        reverse(s.begin(), s.end());
        ans = tail + s + head;
    } else {
        reverse(head.begin(), head.end());
        ans = head + s + tail;
    }
    cout << ans << endl;
    return 0;
}