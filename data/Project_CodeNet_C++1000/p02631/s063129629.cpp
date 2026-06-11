#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define pb push_back
#define vi vector<int>

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x = 0;
    for(int i = 0; i < n; i += 2) {
        x ^= a[i];
        x ^= a[i + 1];
    }
    for(int i = 0; i < n; ++i) {
        cout << (a[i] ^ x) << " \n"[i == n - 1];
    }
    return 0;
}

