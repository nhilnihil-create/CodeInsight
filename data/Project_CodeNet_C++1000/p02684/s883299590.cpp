#include <iostream>
#include <vector>
#include <deque>

using namespace std;
int n;
long long k;
const int MAX_N = 2e5 + 5;
const int D = 60;
int to[D][MAX_N];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> to[0][i];
        to[0][i]--;
    }

    for (int i = 0; i < D - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            to[i + 1][j] = to[i][to[i][j]];
        }
    }

    int v = 0;
    for (int i = D - 1; i >= 0; --i) {
        long long l = (long long) 1 << i; // l = 2^i
        if (l <= k) {
            v = to[i][v];
            k -= l;
        }
    }
    cout << v + 1 << endl;
    return 0;
}