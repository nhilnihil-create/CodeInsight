#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "[(" << __LINE__ << ") " << (#x) << "]: " << x << endl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string ss;
    int q;
    cin >> ss >> q;

    bool flipped = false;
    deque<char> s;
    for (char c : ss) s.push_back(c);

    for (int i=0; i<q; i++) {
        int x;
        cin >> x;
        if (x == 1) flipped = !flipped;
        else {
            char c;
            cin >> x >> c;
            if (flipped == x-1) s.push_front(c);
            else s.push_back(c);
        }
    }
    if (flipped) {
        while (!s.empty()) {
            cout << s.back();
            s.pop_back();
        }
    } else {
        while (!s.empty()) {
            cout << s.front();
            s.pop_front();
        }
    }
    cout << "\n";
}
