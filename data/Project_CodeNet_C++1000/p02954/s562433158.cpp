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

int main(void) {
    string S;
    cin >> S;
    const int slen = (int) S.size();

    vector<int> ans(slen, 0);


    // for R
    {
        int cnt = 0;
        for (int i = 0; i < slen; i++) {
            if (S[i] == 'R') {
                cnt++;
            } else {
                ans[i] += cnt/2;
                ans[i - 1] += cnt - cnt/2;
                cnt = 0;
            }
        }
    }

    // for L
    {
        int cnt = 0;
        for (int i = slen - 1; i >= 0; i--) {
            if (S[i] == 'L') {
                cnt++;
            } else {
                ans[i] += cnt/2;
                ans[i + 1] += cnt - cnt/2;
                cnt = 0;
            }
        }
    }

    cout << ans[0];
    for (int i = 1; i < slen; i++) {
        cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}
