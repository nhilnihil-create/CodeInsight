#include <bits/stdc++.h>
using namespace std;
vector<int> l;
using ll = long long;
int n;
bool ok(int mid, int a, int b) {
    if (l[mid] < l[a] + l[b]) return true;
    else return false;
}
int main() {
    cin >> n;
    l.resize(n);
    for (int i = 0; i < n; i++) cin >> l[i];
    sort(l.begin(), l.end());
    l.push_back(1<<30);
    ll ans = 0;
    for (int a = 0; a < n - 2; a++) {
        for (int b = a + 1; b < n - 1; b++) {
            int bottom = b;
            int top = n;
            while (top - bottom > 1) {
                int mid = (top + bottom) / 2;
                if (ok(mid, a, b)) bottom = mid;
                else top = mid;
            }
            ans += bottom - b;
        }
    }
    cout << ans << endl;
    return 0;
}