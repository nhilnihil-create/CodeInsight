#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < k; ++i) {
        // いもす法
        vector<int> b(n + 1); // 半開区間で考える

        for (int j = 0; j < n; ++j) {
            b[max(j - a[j], 0)]++;
            b[min(j + a[j] + 1, n)]--;
        }

        for (int j = 0; j < n; ++j) {
            b[j + 1] += b[j];
        }

        b.pop_back();

        a = b;
        bool brk = true;
        for (int j = 0; j < n; ++j) {
            if (b[j] != n) {
                brk = false;
                break;
            }
        }

        if (brk) break;
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }

    cout << endl;
}