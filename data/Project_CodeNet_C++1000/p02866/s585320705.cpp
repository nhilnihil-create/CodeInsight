#include<bits/stdc++.h>


int main(void) {
    using namespace std;

    constexpr long MOD = 998244353;
    auto powm = [&](long a, long b) {
        long r = 1;
        while(b) {
            if(b&1) r *= a, r %= MOD;
            a *= a, a %= MOD;;
            b >>= 1;
        }
        return r;
    };

    long n;
    cin >> n;
    vector<long> d(n);
    for(auto &x: d) cin >> x;

    map<long,long> m;
    long mx = 0;
    for(auto &x: d) m[x]++, mx = max(mx, x);

    if(!(d[0] == 0 && m[0] == 1)) {
        cout << 0 << endl;
        return 0;
    }

    long r = 1;
    for(int i=1; i<=mx; i++) {
        r *= powm(m[i-1], m[i]), r %= MOD;
    }

    cout << r << endl;
}
