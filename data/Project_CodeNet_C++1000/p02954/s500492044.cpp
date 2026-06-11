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

vector<int> ls;
vector<int> rs;

int main(void) {
    string S;
    cin >> S;
    const int slen = (int) S.size();

    for (int i = 0; i < slen; i++) {
        if (S[i] == 'L') {
            ls.push_back(i);
        } else {
            rs.push_back(i);
        }
    }

    vector<int> ans(slen, 0);

    for (auto r : rs) {
        auto it = upper_bound(ls.begin(), ls.end(), r);
        const int l = *it;

        if ((l - r) % 2 == 0) {
            ans[l]++;
            // printf("R %d to %d\n",r, l);
        } else {
            ans[l - 1]++;
            // printf("R %d to %d\n",r, l - 1);
        }
    }

    for (auto l : ls) {
        // int left = -1, right = (int) rs.size(), mid;
        // while (right - left > 1) {
        //     mid = left + (right - left) / 2;
        //     if (rs[mid] > l) {
        //         right = mid;
        //     } else {
        //         left = mid;
        //     }
        // }
        // const int r = mid;

        auto it = upper_bound(rs.begin(), rs.end(), l);
        it--;
        const int r = *it;
        if ((l - r) % 2 == 0) {
            ans[r]++;
            // printf("L %d to %d\n", l, r);
        } else {
            ans[r + 1]++;
            // printf("L %d to %d\n", l, r + 1);
        }
    }

    cout << ans[0];
    for (int i = 1; i < slen; i++) {
        cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}
