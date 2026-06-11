#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

vector<int> calc_digits(int n) {
    vector<int> ans;

    if (n == 0) {
        ans.push_back(0);
        return ans;
    }

    while (n > 0) {
        ans.push_back(n % 10);
        n /= 10;
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main(void) {
    int N, M;
    cin >> N >> M;

    // {s, c}
    vector<pair<int, int>> conds(M);
    for (int i = 0; i < M; i++) {
        cin >> conds[i].first;
        cin >> conds[i].second;
    }

    int ans = -1;
    for (int i = 0; i < 1000; i++) {
        vector<int> digits = calc_digits(i);
        // for (int d : digits) {
        //     cout << d << " ";
        // }
        // cout << endl;

        if ((int) digits.size() != N) {
            continue;
        }

        bool ok = true;
        for (auto cond : conds) {
            int s = cond.first;
            s--;
            int c = cond.second;
            if (s >= (int) digits.size()) {
                ok = false;
            }
            if (digits[s] != c) {
                ok = false;
            }
        }

        if (ok) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
