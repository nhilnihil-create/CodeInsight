#include <bits/stdc++.h>

using namespace std;

int n, cnt;
char p = '!', c;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n; cnt = n;
    while (n--) {
        cin >> c;
        if (c == p) cnt--;
        p = c;
    }
    cout << cnt << '\n';

    return 0;
}