#include <bits/stdc++.h>
using namespace std;

void solve () {
    long long n, m;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        mp[x] = 1;
    }
    vector<long long> fibo(2);
    fibo[0] = 0;
    fibo[1] = 1;
    long long md = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
        long long x = fibo[0] + fibo[1];
        fibo[0] = fibo[1];
        if (mp.count(i)) {
            x = 0;
        }
        fibo[1] = x % md;
    }
    cout << fibo[1] << endl;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
