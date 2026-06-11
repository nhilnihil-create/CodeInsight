#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int X = (N - 1) * (N - 2) / 2;
    if (K > X) {
        cout << -1 << "\n";
        return 0;
    }
    cout << N - 1 + X - K << "\n";
    rep(i, N - 1) cout << 1 << " " << 2 + i << "\n";
    int n = 2, m = 3;
    rep(i, X - K) {
        cout << n << " " << m << "\n";
        ++m;
        if (m > N) {
            ++n;
            m = n + 1;
        }
    }
    return 0;
}
