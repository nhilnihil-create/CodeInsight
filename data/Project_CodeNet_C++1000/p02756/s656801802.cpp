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

    deque<char> que;
    for (auto c : S) {
        que.push_back(c);
    }

    int dir = 1;

    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            dir *= -1;
        } else {
            int f;
            char c;
            cin >> f >> c;
            if (f == 1) {
                if (dir == 1) {
                    que.push_front(c);
                } else {
                    que.push_back(c);
                }
            } else {
                if (dir == 1) {
                    que.push_back(c);
                } else {
                    que.push_front(c);
                }
            }
        }
    }

    if (dir == -1) {
        reverse(que.begin(), que.end());
    }

    for (int i = 0; i < (int) que.size(); i++) {
        cout << que[i];
    }
    cout << endl;

    // this is also OK.
    // while (!que.empty()) {
    //     cout << que.front();
    //     que.pop_front();
    // }
    // cout << endl;

    return 0;
}
