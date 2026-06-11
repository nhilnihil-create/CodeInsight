#include<bits/stdc++.h>


int main(void) {
    using namespace std;

    constexpr long MOD = 1e9 + 7;

    long n;
    cin >> n;
    vector<long> a(n);
    for(auto &x: a) cin >> x;

    vector<int> v(1000000);
    long r = 1;
    for(int i=0; i<n; i++) {
        if(a[i] == 0) {
            r *= 3 - v[0]++, r %= MOD;
        } else {
            r *= v[a[i]-1] - v[a[i]]++, r %= MOD;
        }
    }

    cout << r << endl;
}
