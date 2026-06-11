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
 
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int s = 0;
    for (int i = 0; i < n; i++) s += a[i];
    vector<int> d;
    for (int i = 1; i * i <= s; i++) {
        if (s % i == 0) {
            d.push_back(i);
            d.push_back(s / i);
        }
    }
    int res = 1;
    for (int x : d) {
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = a[i] % x;
        }
        sort(b.begin(), b.end());
        int i = 0;
        int j = n - 1;
        long c = 0;
        while (i < j) {
            if (b[i] == 0) i++;
            else if (b[j] == x) j--;
            else {
                int q = min(b[i], x - b[j]);
                b[i] -= q;
                b[j] += q;
                c += q;
            }
        }
//        cout << x << " " << c << "\n";
        if (c <= k) {
            res = max(res, x);
        }
    }
    cout << res << "\n";
 
    return 0;
}