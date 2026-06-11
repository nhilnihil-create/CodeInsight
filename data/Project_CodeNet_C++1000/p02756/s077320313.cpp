#include <bits/stdc++.h>


using namespace std;


int main(void) {
    string S;
    cin >> S;
    list<char> l;
    for (auto ch : S) {
        l.push_back(ch);
    }
    int Q;
    cin >> Q;
    bool reversed = false;
    for (int i = 0; i < Q; i++) {
        int T;
        cin >> T;
        if (T == 1) {
            reversed = !reversed;
            continue;
        }
        int F;
        char C;
        cin >> F >> C;
        if ((!reversed && F == 1) || (reversed && F == 2)) {
            l.push_front(C);
        } else {
            l.push_back(C);
        }
    }
    if (!reversed) {
        for (auto it = l.begin(); it != l.end(); ++it) {
            cout << *it;
        }
        cout << endl;
    } else {
        for (auto it = l.rbegin(); it != l.rend(); ++it) {
            cout << *it;
        }
        cout << endl;
    }
}
