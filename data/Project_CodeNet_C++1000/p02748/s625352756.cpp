#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main() {
    int A, B, M;
    cin >> A >> B >> M;
    int a[A], b[B], mina = INF, minb = INF;
    for (int i = 0; i < A; i++) {
        cin >> a[i];
        mina = min(mina, a[i]);
    }
    for (int i = 0; i < B; i++) {
        cin >> b[i];
        minb = min(minb, b[i]);
    }
    int ans = mina + minb;
    for (int i = 0, x, y, c; i < M; i++) {
        cin >> x >> y >> c;
        x--; y--;
        ans = min(ans, a[x] + b[y] - c);
    }
    cout << ans << endl;
}