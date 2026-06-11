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

    int Q;
    cin >> Q;

    string ls = "";
    string rs = S;

    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            swap(ls, rs);
        } else {
            int f;
            char c;
            cin >> f >> c;

            if (f == 1) {
                ls.push_back(c);
            } else {
                rs.push_back(c);
            }
        }
    }

    reverse(ls.begin(), ls.end());
    cout << ls << rs << endl;

    return 0;
}
