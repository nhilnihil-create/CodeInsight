#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

long long GCD(long long x, long long y) {
    if (x % y == 0) return y;
    else return GCD(y, x % y);
}

long long LCM(long long x, long long y) {
    return (long long)x / GCD(x, y) * y;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    rep(i, n) cin >> a[i];
    
    rep(i, n) a[i] /= 2;
    long long now_lcm = a[0];
    REP(i, n) {
        long long x = LCM(now_lcm, a[i]) / now_lcm;
        long long y = LCM(now_lcm, a[i]) / a[i];
        if (x % 2 == 0 || y % 2 == 0) {
            cout << 0 << endl;
            return 0;
        }
        now_lcm = LCM(now_lcm, a[i]);
        if (now_lcm > m) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << (m / now_lcm + 1) / 2 << endl;
    return 0;
}
