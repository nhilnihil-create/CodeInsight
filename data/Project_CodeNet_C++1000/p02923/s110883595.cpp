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
    int n;
    cin >> n;
    int last = -1;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;cin >> x;
        if (x <= last) cnt++;
        else cnt = 0;
        ans = max(ans, cnt);
        last = x;
    }
    cout << ans;
    return 0;
}