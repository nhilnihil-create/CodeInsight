#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
int n, k;
long long res;
int main() {
    DAU
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = (a[i] + a[i-1]) % k;
    }
    for (int i = 1; i <= n; ++i)
        a[i] = (a[i] + k - i % k) % k;
    map<int, int> freq;
    freq[0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (i >= k)
            --freq[a[i-k]];
        res += freq[a[i]]++;
    }
    cout << res;
    PLEC
}
