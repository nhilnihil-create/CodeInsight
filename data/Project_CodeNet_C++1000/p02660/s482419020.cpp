#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 素因数分解
vector<pair<long long, long long>> prime_factorize(long long n) {
    vector<pair<long long, long long>> res;
    for(long long p = 2; p * p <= n; ++p) {
        if(n % p != 0)
            continue;
        int num = 0;
        while(n % p == 0) {
            ++num;
            n /= p;
        }
        res.push_back(make_pair(p, num));
    }
    if(n != 1)
        res.push_back(make_pair(n, 1));
    return res;
}

int main() {
    ll n, cnt = 2;
    cin >> n;

    int ans = 0;
    auto m = prime_factorize(n);
    for(auto it = m.begin(); it != m.end(); it++) {
        // cout << it->first << "," << it->second << endl;
        int n = it->second;
        for(int i = 1; i <= n; i++) {
            n -= i;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}