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
    int N, D;
    cin >> N >> D;

    int n = N / (2 * D + 1);
    if (N % (2 * D + 1) != 0) {
        n++;
    }

    cout << n << endl;

    return 0;
}
