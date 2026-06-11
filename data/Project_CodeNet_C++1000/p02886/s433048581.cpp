#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    vector<int> D(N, 0);
    int ans = 0;
    for (int i = 0; i < N; ++i) cin >> D[i];
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            ans += D[i] * D[j];
        }
    }
    printf("%d\n", ans);
}
