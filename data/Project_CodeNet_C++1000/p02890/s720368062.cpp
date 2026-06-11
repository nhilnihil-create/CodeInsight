#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> b(n, 0), s(n+1, 0);
    for (int i = 0; i < n; i++) { int a; cin >> a; b[a-1]++; }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) s[i+1] = b[i] + s[i];
    vector<int> f(n+1, 1<<30);
    for (int x = 1; x <= n; x++) {
        int i = lower_bound(b.begin(), b.end(), x) - b.begin();
        f[x] = n - i + s[i]/x;
    }
    for (int k = 1; k <= n; k++)
        cout << f.rend() - lower_bound(f.rbegin(), f.rend(), k) - 1 << endl;
}
