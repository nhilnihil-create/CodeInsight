#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

const int INF = 1e9;
const long long LINF = 1e18;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (((p[i] < p[i - 1]) && (p[i] > p[i + 1])) || ((p[i] < p[i + 1]) && (p[i] > p[i - 1]))) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
