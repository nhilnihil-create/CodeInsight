#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    vector<int> input(3);
    rep(i, 3) cin >> input[i];
    rep(i, 3) {
        if (input[i] == input[(i + 1) % 3] &&
            input[(i + 1) % 3] != input[(i + 2) % 3]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}