
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, cnt;
int bits(int x) {
    int res = 0;
    while (x) {
        ++res;
        x /= 10;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (bits(i) & 1)
            ++cnt;
    }
    cout << cnt << endl;

    return 0;
}

