#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

int n, k;
int a[N];

bool chk(int x) {
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += (a[i] + x - 1) / x - 1;
        if (res > k) return false;
    }
    return true;
}

void run() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 1, r = INF, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (chk(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    run();
    return 0;
}
