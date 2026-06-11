#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int cnt = 0;
    while (n-- > 0) {
        cnt += n;
    }
    while (m-- > 0) {
        cnt += m;
    }

    cout << cnt << endl;

    return 0;
}
