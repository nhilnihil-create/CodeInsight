#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    int k = 1;
    stack<int> s;
    rep(i, n) {
        if (a[i] == k) {
            s.push(k);
            k++;
        }
    }
    if (s.empty()) {
        cout << -1 << endl;
    } else {
        cout << (n - s.size()) << endl;
    }
}