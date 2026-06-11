#include <iostream>
using namespace std;

const int maxn = 1e5 + 5;

int A, B, M, a[maxn], b[maxn], x[maxn], y[maxn], c[maxn];

int main() {
    cin >> A >> B >> M;
    for (int i=0; i<A; i++) {
        cin >> a[i];
    }
    for (int i=0; i<B; i++) {
        cin >> b[i];
    }
    for (int i=0; i<M; i++) {
        cin >> x[i] >> y[i] >> c[i];
    }
    int ans = 0, besta = a[0], bestb = b[0];
    for (int i=0; i<A; i++) {
        besta = min(besta, a[i]);
    }
    for (int i=0; i<B; i++) {
        bestb = min(bestb, b[i]);
    }
    ans = besta + bestb;
    for (int i=0; i<M; i++) {
        ans = min(ans, a[x[i] - 1] + b[y[i] - 1] - c[i]);
    }
    cout << ans << "\n";
}