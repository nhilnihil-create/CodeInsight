#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int q, t_cnt = 0;
    cin >> s >> q;
    deque<char> str;
    for (size_t i = 0; i < s.size(); i++) {
        str.push_back(s.at(i));
    }
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            t_cnt++;
        } else {
            int f;
            char c;
            cin >> f >> c;
            if (t_cnt % 2 == 0) {
                f == 1 ? str.push_front(c) : str.push_back(c);
            } else {
                f == 2 ? str.push_front(c) : str.push_back(c);
            }
        }
    }
    if (t_cnt % 2 == 1) reverse(str.begin(), str.end());
    for (auto &x : str) cout << x;
    cout << endl;
}
