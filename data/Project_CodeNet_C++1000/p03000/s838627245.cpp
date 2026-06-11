#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, X; cin >> N >> X;
    vector<int> L(N, 0);
    for (int i = 0; i < N; ++i) cin >> L[i];
    vector<int> D(N + 1, 0);
    int cnt = 0;
    for (int i = 1; i < N + 1; ++i) {
        D[i] = D[i - 1] + L[i - 1];
        if (D[i] <= X) cnt++;
    }
    printf("%d\n", cnt + 1);
}
