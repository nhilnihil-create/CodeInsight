#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 100;

int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a(A), b(B);
    for(int i = 0; i < A; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < B; i++) {
        cin >> b[i];
    }
    int ans = 1e9;
    for(int i = 0; i < M; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--, y--;
        ans = min(ans, a[x]+b[y]-c);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ans = min(ans, a[0] + b[0]);
    cout << ans << endl;

    return 0;
}

