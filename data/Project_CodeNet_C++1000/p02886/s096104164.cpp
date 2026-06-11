#include<bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            sum += v[i] * v[j];
        }
    }
    cout << sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}
