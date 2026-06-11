#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int p[30];
    int n, cnt = 0;
    cin >> n;
    rep(i, n) { cin >> p[i]; }
    for (int i = 1; i < n - 1; ++i) {
        if ((p[i - 1] < p[i]) && (p[i] < p[i + 1])) {
            cnt++;
        } else if ((p[i - 1] > p[i]) && (p[i] > p[i + 1])) {
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}