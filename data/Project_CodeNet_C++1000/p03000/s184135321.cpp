#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X; cin >> N >> X;
    vector<int> D(N + 1);
    D[0] = 0;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        D[i + 1] = D[i] + x;
    }
    int ans = 0;
    for (int i = 0; i <= N; ++i) {
        if (D[i] <= X) {
        ans++;
        }
    }
cout << ans << endl;
return 0;
}
