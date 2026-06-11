#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repk(i, k, n) for (int i = k; i < n; i++)
#define MOD 1000000007
#define INF 1e9
#define PIE 3.14159265358979323

template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
T GCD(T a, T b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
template <class T>
inline T LCM(T a, T b) {
    return (a * b) / GCD(a, b);
}

int main() {
    int n;
    cin >> n;
    int m = n;
    int cnt = 0;
    while (m) {
        m /= 10;
        cnt++;
    }
    vector<vector<int>> table(9, vector<int>(9, 0));
    for (int i = 1; i <= n; i++) {
        int head = i;
        while (true) {
            if (head < 10) {
                break;
            }
            head /= 10;
        }
        int tail = i % 10;
        if (tail > 0) {
            table[head - 1][tail - 1]++;
        }
        else
            continue;
    }
    int sum = 0;
    rep(i, 9) rep(j, 9) {
        sum += table[i][j] * table[j][i];
    }
    cout << sum << endl;
    return 0;
}