#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    int n;
    cin >> n;
    vector<long long> a(n);
    long long x = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        x ^= a[i];
    }
    for (int i = 0; i < n; i++) cout << (x ^ a[i]) << ' ';
    cout << '\n';
}