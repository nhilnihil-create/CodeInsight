#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;

    vector<int> hoge(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (hoge[i]) continue;
        cnt++;
        for (int j = i; j < min(n, i + 2 * d + 1); j++) {
            hoge[j] = 1;
        }
    }
    cout << cnt << endl;
}
