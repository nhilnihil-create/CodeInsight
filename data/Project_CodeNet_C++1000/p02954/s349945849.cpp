#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using ll = long long;
#define rep(inc, bgn, end) for (int inc = bgn; inc < end; ++inc)
#define repe(inc, bgn, end) for (int inc = bgn; inc <= end; ++inc)

using namespace std;
int main() {
    string str;
    cin >> str;

    vector<int> idx;
    // O:n
    rep(i, 0, str.size() - 1) {
        if (str[i] == 'R' && str[i + 1] == 'L') {
            idx.push_back(i);
        }
    }

    idx.push_back(10001000);

    //
    int nextidx = 0;
    int previdx = -1;
    vector<int> pos(str.size(), 0);
    rep(i, 0, str.size()) {
        // update idx
        if (i > idx[nextidx]) {
            nextidx++;
            previdx++;
        }

        int _idx = -1;
        if (str[i] == 'R') {
            _idx = idx[nextidx];
        } else {
            _idx = idx[previdx];
        }
        pos[_idx + (abs(_idx - i) % 2)]++;
    }

    // print result
    rep(i, 0, pos.size()) {
        cout << pos[i];
        if (i < pos.size() - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }

    return 0;
}
