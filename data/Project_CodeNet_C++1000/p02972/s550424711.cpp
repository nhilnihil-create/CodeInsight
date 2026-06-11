#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L
const int mxN = 1e9 + 7;

char s[100005];
long long dp[100005][13];

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(n);
    set<int> s;
    for (int i = n - 1; i >= 0; i--) {
        int cnt = 0;
        for (int j = i; j < n; j+= i+1) {
            cnt += b[j];
        }
        if (cnt % 2 != a[i]) {
            b[i] = 1;
            s.insert(i + 1);
        }
    }
    bool ok = true;
    for (int i = n - 1; i >= 0; i--) {
        int cnt = 0;
        for (int j = i; j < n; j+= i+1) {
            cnt += b[j];
        }
        if (cnt % 2 != a[i]) ok = false;
    }
    if (ok) {
        cout << s.size() << "\n";
        for (auto x : s) cout << x << " ";
    }
    else {
        cout << -1;
    }
    return 0;
}