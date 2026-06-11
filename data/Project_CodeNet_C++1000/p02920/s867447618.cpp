#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    n = 1 << n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());
    vector<bool> z(n);
    z[0] = true;
    vector<int> b = {a[0]};
    int c = 1;
    while (c < n) {
        int j = 0;
        for (int i = 0; i < c; i++) {
            while (j < n && (z[j] || a[j] >= b[i])) j++;
            if (j == n) {
                cout << "No";
                return 0;
            }
            z[j] = true;
            b.push_back(a[j]);
        }
        sort(b.rbegin(), b.rend());
        c *= 2;
    }
    cout << "Yes";

    return 0;
}