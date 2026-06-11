#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p[50];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];

    int ans = 0;
    for (int i = 1; i + 1 < n; i++) {
        if (p[i] > p[i - 1] && p[i] < p[i + 1]) ans++;
        else if (p[i] < p[i - 1] && p[i] > p[i + 1]) ans++;
    }

    cout << ans << endl;
}