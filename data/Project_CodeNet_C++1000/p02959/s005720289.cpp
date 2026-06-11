#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L
const int mxN = 1e9 + 7;

bool is_sorted(vector<int> a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1]) return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 0; i <= n; i++) cin >> a[i];
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int x = min(b[i], a[i]);
        ans += x;
        b[i] -= x;
        int y = min(b[i], a[i+1]);
        a[i + 1] -= y;
        ans += y;
    }
    cout << ans;

    return 0;
}