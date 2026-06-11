#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    int ans = T.size(), diff = 0;

    for (int i = 0; i < S.size(); i++) {
        if (S.at(i) != T.at(i)) {
            diff++;
        }
    }
    ans = min(ans, diff);

    cout << ans << endl;
}