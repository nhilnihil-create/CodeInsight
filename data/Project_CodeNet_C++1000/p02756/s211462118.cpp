#include <bits/stdc++.h>
using namespace std;

// D - String Formation
int main() {
    string S;
    cin >> S;
    list<char> result;
    for (int i = 0; i < S.size(); i++) {
        result.push_back(S[i]);
    }

    int Q;
    cin >> Q;

    bool isReverse = false;
    bool isFrontAdd = false;
    int T, F;
    char C;
    for (int i = 0; i < Q; i++) {
        cin >> T;
        if (T == 1) {
            isReverse = !isReverse;
        } else {
            cin >> F;
            cin >> C;
            if (F == 1) {
                isFrontAdd = !isReverse;
            } else {
                isFrontAdd = isReverse;
            }
            if (isFrontAdd) {
                result.push_front(C);
            } else {
                result.push_back(C);
            }
        }
    }

    while (!result.empty()) {
        if (isReverse) {
            cout << result.back();
            result.pop_back();
        } else {
            cout << result.front();
            result.pop_front();
        }
    }
}
