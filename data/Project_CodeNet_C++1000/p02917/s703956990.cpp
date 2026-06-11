#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> b(n-1);
    rep(i, n-1) cin >> b[i];
    vector<int> a(n);
    rep(i, n) {
        if (i == 0) {
            a[i] = b[i];
        }
        else if (i == n-1) {
            a[i] = b[i-1];
        }
        else {
            a[i] = min(b[i-1], b[i]);
        }
    }
    cout << accumulate(a.begin(), a.end(), 0) << endl;
}