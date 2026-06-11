#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n,0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    long long comfort = 0;
    for (int i = 0; i < n; i++) {
        if (i == 1) {
            comfort += a[i-1];
        }
        if (i > 1) comfort += a[i/2];
    }
    cout << comfort;
}
