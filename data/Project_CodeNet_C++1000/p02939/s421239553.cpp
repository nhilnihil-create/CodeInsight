#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <functional>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

int main() {
    string S;
    cin >> S;
    int ans = 0;
    string T = "";
    rep(i, S.size()) {
        int o = ans;
        for (int j = 1; j <= S.size() - i; ++j) {
            if (S.substr(i, j) != T) {
                ++ans;
                T = S.substr(i, j);
                i += j - 1;
                break;
            }
        }
        if (o == ans) {
            T.push_back(S[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}
