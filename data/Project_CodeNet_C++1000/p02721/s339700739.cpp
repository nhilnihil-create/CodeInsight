#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    int f[k], b[k];
    int i = 0, j = 0;
    while (i < n && j < k) 
    {
        if (s[i] == 'o') {
            f[j++] = i;
            i = i + c + 1;
        }else ++i;
    }
    i = n - 1, j = k - 1;
    while (i >= 0 && j >= 0) {
        if (s[i] == 'o') {
            b[j--] = i;
            i -= (c + 1);
        }else --i;
    }

    for (int i = 0; i < k; ++i) {
        if (f[i] == b[i]) {
            cout << f[i] + 1 << endl;
        }
    }
    return 0;
}