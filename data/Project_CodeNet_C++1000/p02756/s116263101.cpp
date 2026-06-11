#include <iostream>
#include <algorithm>
#include <limits>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <deque>
#include <stack>
#include <queue>

using namespace std;
string s;
int q;

int main() {
    bool reversed = false;
    cin >> s;
    cin >> q;
    stack<char> front, back;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            reversed = !reversed;
        } else if (t == 2) {
            int f;
            char c;
            cin >> f >> c;
            if (f == 1) {
                if (reversed) {
                    back.push(c);
                } else {
                    front.push(c);
                }
            } else if (f == 2) {
                if (reversed) {
                    front.push(c);
                } else {
                    back.push(c);
                }
            }
        }
    }
    string prefix, suffix;
    while (!front.empty()) {
        prefix += front.top();
        front.pop();
    }
    while (!back.empty()) {
        suffix += back.top();
        back.pop();
    }

    string ans;
    if (reversed) {
        reverse(prefix.begin(), prefix.end());
        reverse(s.begin(), s.end());
        ans = suffix + s + prefix;
    } else {
        reverse(suffix.begin(), suffix.end());
        ans = prefix + s + suffix;
    }
    cout << ans << endl;
    return 0;
}
