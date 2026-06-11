#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;

    int idx = 1;
    rep(i, n) {
        int a;
        cin >> a;
        if (a == idx) idx++;
    }

    if (idx == 1)
        cout << -1 << endl;
    else
        cout << n - (idx - 1) << endl;
    return 0;
}
