// solv_E.cpp : 
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;


ull N, K;


const ull mod = ull(1E9) + 7;

ull my_plus(ull a, ull b) {
    return ((a % mod + b % mod) % mod);
}

ull my_minus(ull a, ull b) {
    ll ans;
    ans = (a % mod - b % mod);

    if (ans < 0) {
        ans += mod;
    }

    return ull(ans);
}


ull my_mult(ull a, ull b) {
    return ((a % mod * b % mod) % mod);
}

ull my_power(ull x, ull n) {
    ull p, ans;
    ull b;
    ull i;

    ans = 1;

    p = x;
    b = n;

    // cout << "--- x=" << x << " n=" << n << endl;

    while (b != 0){
        if (b & 1) {
            ans = my_mult(ans, p);
        }
        b = b >> 1;
        p = my_mult(p, p);

        // cout << b << " p=" << p << " ans=" << ans<< endl;
    }


    return ans;

}


ull result1;
ull counter[100001];

int main()
{
    ull result1, result2, result3;
    ull num_primes, num_coprimes = 0;

    cin >> N >> K;

    ull i, j;

#ifdef CHECK
    ll tmp = 1;
    for (i = 1; i <= N; i++) {
        cout << "K^"<< i << "=" << my_power(K, i) << endl;
        tmp = my_mult(tmp, K);
        cout << "tmp=" << tmp << endl;
    }

    exit(0);
#endif


    ull result12 = 0;
    for (ull k = K; k >= 1; k--) {
        ull p = ull(K / k);

#ifdef ORIG
        result1 = 1;
        for (ll i = 1; i <= N; i++) {
            result1 = my_mult(result1, p);
        }
#endif
        result1 = my_power(p, N);

        // cout << result1 << endl;

        for (ull i = k*2; i <= K; i+=k) {
            // result1 = result1 - counter[i];
            result1 = my_minus(result1, counter[i]);
            // cout << "i=" << i << " counter[i]=" << counter[i] << " result1=" << result1 << endl;
        }

        counter[k] = result1;
        result12 = my_plus(result12, my_mult(counter[k], k));

        //cout << "k=" << k << " counter[k]=" << counter[k] << " result12=" << result12 << endl;
    }

    cout << result12 << endl;
}

