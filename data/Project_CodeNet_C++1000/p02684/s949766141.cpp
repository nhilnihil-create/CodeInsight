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

vector<int> to;

int detect_loop(const int cur, vector<bool> &visited) {
    if (visited[cur]) {
        return cur;
    }
    visited[cur] = true;
    return detect_loop(to[cur], visited);
}

int main(void) {
    int N;
    ll K;
    cin >> N >> K;

    to.resize(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        a--;
        to[i] = a;
    }

    int loop_start;
    {
        vector<bool> visited(N, false);
        loop_start = detect_loop(0, visited);
    }
    // printf("loop_start: %d\n", loop_start);

    // 0 -> 5 -> 1 for sample2
    vector<int> vs_till_loop;
    {
        int cur = 0;
        while (cur != loop_start) {
            vs_till_loop.push_back(cur);
            cur = to[cur];
        }
    }
    vs_till_loop.push_back(loop_start);
    // for (auto x : vs_till_loop) {
    //     cout << x << " ";
    // }
    // cout << endl;

    // 1 -> 4 -> 2 for sample1
    vector<int> vs_in_loop;
    vs_in_loop.push_back(loop_start);
    {
        int cur = to[loop_start];
        while (cur != loop_start) {
            vs_in_loop.push_back(cur);
            cur = to[cur];
        }
    }
    // for (auto x : vs_in_loop) {
    //     cout << x << " ";
    // }
    // cout << endl;

    const int steps_till_loop = (int) vs_till_loop.size() - 1;
    if (K <= steps_till_loop) {
        cout << vs_till_loop[K] + 1 << endl;
    } else {
        cout << vs_in_loop[(K - (steps_till_loop)) % ((int) vs_in_loop.size())] + 1 << endl;
    }

    return 0;
}
