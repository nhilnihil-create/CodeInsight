#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L


int Z_algo(string s, int k) {
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
    for (int i = k; i < n; i++) mx = max(mx, z[i]);
    return mx;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mx = 0;
    for (int i = n-1; i >= 0; i--) {
        mx = max(mx, Z_algo(s.substr(i, n-i) + "#" + s.substr(0, i), n-i));
    }
    cout << mx;
    return 0;
}