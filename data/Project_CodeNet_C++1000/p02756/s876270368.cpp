#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    int Q, cnt = 0; cin >> S >> Q;
    vector<pair<int, char>> formation(S.size());
    for (int i = 0; i < S.size(); i++) {
        formation.at(i) = make_pair(i, S.at(i));
        cnt++;
    }
    int left = 0, right = cnt-1;
    bool key = true;
    for (int i = 0; i < Q; i++) {
        int query; cin >> query;
        if (query == 1) {
            if (key) key = false;
            else key = true;
        } else {
            int F;
            char C; cin >> F >> C;
            cnt++;
            if (key) {
                if (F == 1) {
                    left--;
                    formation.push_back(make_pair(left, C));
                } else {
                    right++;
                    formation.push_back(make_pair(right, C));
                }
            } else {
                if (F == 1) {
                    right++;
                    formation.push_back(make_pair(right, C));
                } else {
                    left--;
                    formation.push_back(make_pair(left, C));
                }
            }
        }
    }
    sort(formation.begin(), formation.end());
    if (key) {
        for (int i = 0; i < cnt; i++) {
            cout << formation.at(i).second;
        }
    } else {
        for (int i = cnt - 1; i >= 0; i--) {
            cout << formation.at(i).second;
        }
    }
    cout << endl;
}