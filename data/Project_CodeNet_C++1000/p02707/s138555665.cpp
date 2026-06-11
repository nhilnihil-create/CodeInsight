#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n - 1) {
        int x;
        cin >> x;
        a[x - 1]++;
    }

    rep(i, n) cout << a[i] << endl;
    return 0;
}
