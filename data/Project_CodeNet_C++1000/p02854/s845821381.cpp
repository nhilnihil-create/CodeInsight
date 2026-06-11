#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long a;
    vector<long long> b(n);
    cin >> a;
    b[0] = a;
    for (int i = 1; i < n; i++) {
        cin >> a;
        b[i] = b[i-1] + a;
    }
    long long sum = b[n-1];
    long long ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        long long tmp = abs (sum - 2*b[i]);
        ans = min (ans, tmp);
    }
    cout << ans << endl;
}