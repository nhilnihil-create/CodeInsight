#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, D; cin >> N >> D;
    vector<vector<int>> X(N, vector<int>(D, 0));
    for (int i = 0; i < N; i++) for (int j = 0; j < D; j++) cin >> X[i][j];
    int cnt = 0; double x = 1.0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            double M = 0.0;
            for (int k = 0; k < D; ++k) {
                M += pow(X[i][k] - X[j][k], 2);
            }
            if (modf(sqrt(M), &x) == 0) cnt++;
        }
    }
    printf("%d\n", cnt);
}
