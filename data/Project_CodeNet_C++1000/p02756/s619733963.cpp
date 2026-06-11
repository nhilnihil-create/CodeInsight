#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string str;
    cin >> str;
    deque<string> deq;
    for (auto &&c : str) {
        deq.push_back(string(1, c));
    }
    int q;
    cin >> q;
    int rev = 0;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            rev = 1 - rev;
        }
        else {
            int f;
            cin >> f;
            f--;
            string c;
            cin >> c;
            if (f == rev) {
                deq.push_front(c);
            }
            else {
                deq.push_back(c);
            }
        }
    }
    string ans = "";
    for (auto &&c : deq) {
        ans += c;
    }
    if (rev) {
        reverse(ans.begin(), ans.end());
    }
    cout << ans << endl;
    return 0;
}