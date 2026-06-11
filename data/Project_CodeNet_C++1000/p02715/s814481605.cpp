#include<bits/stdc++.h>

int main(){
    using namespace std;
    constexpr unsigned long MOD = 1000000007;
    unsigned long N, K;
    cin >> N >> K;
    unsigned long B{min(K, static_cast<unsigned long>(pow(K / log(log(K + 2)), 2.0L / 3) + 1))};
    vector<unsigned long> phi_small(B + 1);
    for(unsigned long i{0}; i <= B; ++i)phi_small[i] = i;
    vector sieve(B + 1, 1UL);
    for(unsigned long p{2}; p <= B; ++p)if(sieve[p])for(unsigned long i{B / p}; i; --i){
        sieve[i * p] = 0;
        phi_small[i * p] -= phi_small[i];
    }
    partial_sum(phi_small.begin(), phi_small.end(), phi_small.begin());
    vector<unsigned long> phi_large(K / B + 1);
    const auto& phi_sum = [&B, &K, &phi_small, &phi_large](unsigned long i){
        if(i <= B)return phi_small[i];
        return phi_large[K / i];
    };
    for(unsigned long i{K / B}; i; --i){
        auto t = K / i;
        phi_large[i] = t * (t + 1) / 2;
        for(unsigned long k{t}; k > 1;){
            phi_large[i] -= phi_sum(t / k) * (k - t / (t / k + 1));
            k = t / (t / k + 1);
        }
    }
    const auto& modpow = [&N](unsigned long a, unsigned long b) -> unsigned long {
        unsigned long r{b % MOD}, n{N};
        while(n){
            if(n & 1)(r *= a) %= MOD;
            (a *= a) %= MOD;
            n >>= 1;
        }
        return r;
    };
    unsigned long ans{0};
    for(unsigned long i{K}; i; ){
        ans += modpow(K / i, phi_sum(i) - phi_sum(K / (K / i + 1)));
        i = K / (K / i + 1);
    }
    cout << ans % MOD << endl;
    return 0;
}