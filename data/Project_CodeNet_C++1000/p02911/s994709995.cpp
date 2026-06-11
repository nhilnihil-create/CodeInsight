#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(q);
    for (int i = 0; i < q; i++) {
        cin >> a.at(i);
    }
    vector<int> cnt(n);
    for (int i = 0; i < q; i++) {
        cnt.at(a.at(i) - 1)++;
    }
    for (int i = 0; i < n; i++) {
        if (k > q - cnt.at(i)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}