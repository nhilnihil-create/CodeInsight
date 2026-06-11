#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
constexpr int64_t MOD = 1'000'000'007;

template< typename T >
T mod_pow(T x, T n) {
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x) %= MOD;
        (x *= x) %= MOD;
        n >>= 1;
    }
    return ret;
}

int main(void) {
    string L;
    cin >> L;
    int64_t l = L.size();

    int64_t ans = 0;
    int64_t cnt = 0;
    for(int i=0; i<l; i++) {
        if(L[i] == '1') {
            ans += mod_pow(3L, l-1-i) * mod_pow(2L, cnt);
            ans %= MOD;
            cnt++;
        }
    }

    ans += mod_pow(2L, cnt);
    ans %= MOD;

    cout << ans << endl;
    return 0;
}
