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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b = a;
    sort(b.rbegin(), b.rend());
    for (int i = 0; i < n; i++) {
        if (b[0] == a[i]) cout << b[1] << "\n";
        else cout << b[0] << "\n";
    }
    return 0;
}