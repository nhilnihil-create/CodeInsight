#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L


int Z_algo(string s) {
    int n = s.length();
    vector<int> z(n);
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R - L] == s[R]) R++;
            z[i] = R - L; R--;
        }
        else {
            int k = i - L;
            if (z[k] < R - i + 1) z[i] = z[k];
            else {
                L = i;
                while (R < n && s[R - L] == s[R]) R++;
                z[i] = R - L; R--;
            }
        }
    }
    int mx = 0;
    for (int i = 0; i < n; i++) mx = max(mx, min(i, z[i]));
    return mx;
}
const int mxN = 1e9 +7;

int main() {
    long long n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            int x; cin >> x; x--;
            a[i].push_back(x);
        }
    }
    vector<int> pos(n);
    int days = 0;
    while (true) {
        vector<bool> visited(n);
        bool ok = false;
        for (int j = 0; j < n; j++) {
            if (visited[j] || pos[j] == n - 1) continue;
            if (visited[a[j][pos[j]]]) continue;
            if (a[a[j][pos[j]]][pos[a[j][pos[j]]]] == j) {
                pos[a[j][pos[j]]]++;
                visited[j] = true;
                visited[a[j][pos[j]]] = true;
                pos[j]++;
                ok = true;
            }
        }
        if (!ok) {
            break;
        }
        days++;
    }
    bool good = true;
    for (int i = 0; i < n; i++) {
        if (pos[i] != n-1) good = false;
    }
    if (!good) {
        cout << -1;
    }
    else {
        cout << days;
    }
    return 0;
}