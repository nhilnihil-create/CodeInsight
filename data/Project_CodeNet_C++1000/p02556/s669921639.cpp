#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(a) (a).begin(),(a).end()
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        a[i] = x + y;
        b[i] = x - y;
    }
    sort(all(a));
    sort(all(b));
    cout << max(a[n-1] - a[0], b[n-1] - b[0]) << endl;
    return 0;
}