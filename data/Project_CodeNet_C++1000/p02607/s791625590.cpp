#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if (i % 2 == 1 && a % 2 == 1)
            cnt++;
    }
    cout << cnt << endl;
}