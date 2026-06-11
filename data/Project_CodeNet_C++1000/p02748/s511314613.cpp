#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a(A), b(B);
    rep(i, A) cin >> a.at(i);
    rep(i, B) cin >> b.at(i);
    int minA = *min_element(a.begin(), a.end());
    int minB = *min_element(b.begin(), b.end());
    int ans = minA + minB;

    rep(i, M) {
        int x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        ans  = min(ans, a[x] + b[y] - c);
    }

    cout << ans << endl;
}
