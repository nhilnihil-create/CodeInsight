#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void factorization(ll N, vector<ll> &fac) {
    for (ll i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            fac.push_back(i);
            if (i != N/i) 
                fac.push_back(N/i);
        }
    }
    if (N != 1)
        fac.push_back(N);
    sort(fac.begin(), fac.end());
}

int main() {
    ll N, ans;   cin >> N;
    vector<ll> fac, fac1;
    factorization(N, fac);
    factorization(N-1, fac1);
    ans = fac1.size();
    
    for (auto k: fac) {
        ll n = N;
        while (n%k == 0)
            n /= k;
        if (n%k == 1)
            ans++;
    }

    cout << ans << endl;

    return 0;
}