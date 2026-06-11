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
    int N, X, Y;
    cin >> N >> X >> Y;
    X--;
    Y--;

    vector<int> ans(N);

    for (int left = 0; left < N; left++) {
        for (int right = left + 1; right < N; right++) {
            int dist = right - left;
            chmin(dist, abs(left - X) + 1 + abs(right - Y));
            // printf("(%d, %d): %d\n", left, right, dist);
            ans[dist]++;
        }
    }

    for (int i = 1; i <= N - 1; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
