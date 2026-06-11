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
    int K;
    cin >> K;

    queue<ll> q;
    for (int i = 1; i <= 9; i++) {
        q.push(i);
    }

    int cur_no = 0;

    while (!q.empty()) {
        ll cur = q.front();
        q.pop();
        cur_no++;
        if (cur_no == K) {
            cout << cur << endl;
            break;
        }

        int d = cur % 10;
        if (d != 0) {
            q.push(cur * 10 + (d - 1));
        }
        q.push(cur * 10 + d);
        if (d != 9) {
            q.push(cur * 10 + (d + 1));
        }
    }

    return 0;
}
