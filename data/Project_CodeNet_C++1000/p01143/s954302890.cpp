#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, P;
    while (cin >> N >> M >> P && (N || M || P)) {
        vector<int> X(N);
        for (int i=0; i<N; ++i) {
            cin >> X[i];
        }
        if (X[M-1] == 0) {
            cout << 0 << endl;
        } else {
            int ret = accumulate(X.begin(), X.end(), 0) * 100 * (1.0 - P / 100.0) / X[M-1] + 1e-9;
            cout << ret << endl;
        }
    }
    return 0;
}