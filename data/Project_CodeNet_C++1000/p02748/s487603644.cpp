#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int A, B, M; cin >> A >> B >> M;
    vector<int> a(A, 0);
    vector<int> b(B, 0);
    int tmp_a = 10e9 + 1, tmp_b = 10e9 + 1;
    for (int i = 0; i < A; ++i) {
        cin >> a[i];
        tmp_a = min(tmp_a, a[i]);
    }
    for (int i = 0; i < B; ++i) {
        cin >> b[i];
        tmp_b = min(tmp_b, b[i]);
    }
    int ans = tmp_a + tmp_b;
    for (int i = 0; i < M; ++i) {
        int x, y, z; cin >> x >> y >> z;
        if (ans > (a[x - 1] + b[y - 1]) - z) ans = (a[x - 1] + b[y - 1]) - z;
    }
    printf("%d\n", ans);
}
