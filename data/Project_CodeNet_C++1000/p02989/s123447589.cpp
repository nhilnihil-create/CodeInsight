#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    int k;
    sort(d.begin(), d.end());
    if (n % 2) {
        k = 0;
    } else {
        k = d.at(n / 2) - d.at(n / 2 - 1);
    }
    cout << k << endl;
    return 0;
}