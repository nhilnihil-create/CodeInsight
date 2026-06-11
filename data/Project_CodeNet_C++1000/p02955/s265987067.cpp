#include <bits/stdc++.h>
using namespace std;

template<typename T> vector<T> divisor(T n){
    vector<T> res;
    for (long long i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            res.emplace_back(i);
            if (i * i != n) { res.emplace_back(n/i); }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long sum = accumulate(a.begin(), a.end(), 0LL);
    vector<long long> div = divisor(sum);
    
    auto f = [&] (long long x) {
        vector<long long> v(n), sum(n+1, 0);
        for (int i = 0; i < n; i++) v[i] = a[i] % x;
        sort(v.rbegin(), v.rend());
        for (int i = 0; i < n; i++) sum[i+1] = sum[i] + v[i];
        bool ret = false;
        for (int i = 1; i <= n; i++) {
            long long res1 = i * x - sum[i];
            long long res2 = sum[n] - sum[i];
            ret |= (max(res1, res2) <= k);
        }
        return ret;
    };
    
    long long ans = 1;
    for (const auto& x : div) if (f(x)) ans = x;
    cout << ans << endl;
    return 0;
}