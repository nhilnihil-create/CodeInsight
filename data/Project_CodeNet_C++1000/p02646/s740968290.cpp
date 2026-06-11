
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <iostream>
#include <set>
#include <queue>
#include <vector>

using namespace std;

bool solve() {
    int A, B, V, W, T;
    cin >> A >> V;
    cin >> B >> W;
    cin >> T;

    if (V <= W)
        return false;
    return abs(A - B) <=  1LL * (V - W) * T;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (solve())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
