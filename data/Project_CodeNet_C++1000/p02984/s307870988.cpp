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

const int INF = 1e9;
const long long LINF = 1e18;

int main() {
    int N;
    cin >> N;

    long long x1 = 0;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i & 0x1) {
            x1 -= A[i];
        } else {
            x1 += A[i];
        }
    }

    long long ans = x1;
    cout << ans << ' ';

    for (int i = 0; i < N - 1; i++) {
        ans = 2L * A[i] - ans;
        cout << ans;
        if (i != N - 1) {
            cout << ' ';
        }
    }

    cout << endl;

    return 0;
}