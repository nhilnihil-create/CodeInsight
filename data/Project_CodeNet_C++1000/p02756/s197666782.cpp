#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "[(" << __LINE__ << ") " << (#x) << "]: " << x << endl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int q;
    cin >> s >> q;

    bool flipped = false;
    deque<char> bg, ed;

    for (int i=0; i<q; i++) {
        int x;
        cin >> x;
        if (x == 1) flipped = !flipped;
        else {
            char c;
            cin >> x >> c;
            if (flipped == x-1) bg.push_front(c);
            else ed.push_back(c);
        }
    }
    if (flipped) {
        while (!ed.empty()) {
            cout << ed.back();
            ed.pop_back();
        }
        reverse(s.begin(), s.end());
        cout << s;
        while (!bg.empty()) {
            cout << bg.back();
            bg.pop_back();
        }
    } else {
        while (!bg.empty()) {
            cout << bg.front();
            bg.pop_front();
        }
        cout << s;
        while (!ed.empty()) {
            cout << ed.front();
            ed.pop_front();
        }
    }
    cout << "\n";
}
