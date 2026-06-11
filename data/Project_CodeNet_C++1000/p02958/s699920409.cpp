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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b = a;
    sort(b.begin(), b.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) cnt++;
    }
    if (cnt > 2) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }

    return 0;
}