#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> Pil;

ll N;

vector<ll> primeFactorization(ll n) {
    vector<ll> ret;
    ll a = 2;
    while (n >= a * a) {
        if (n % a == 0) {
            ret.push_back(a);
            n /= a;
        } 
        else a++;
    }
    ret.push_back(n);
    return ret;
}

int main() {
    cin >> N;

    if (N == 1) cout << 0 << endl;
    else {
        vector<ll> vec = primeFactorization(N);

        map<ll, ll> mp;
        for (int i = 0; i < vec.size(); i++) {
            mp[vec[i]]++;
        }

        ll ans = 0;
        for (auto itr = mp.begin(); itr != mp.end(); itr++) {
            ll val = itr->second;
            ll i = 1;
            while (i * (i-1) <= 2 * val) {
                i++;
            }
            //cout << val << ":" << i << endl;
            ans += i-2;
        }

        cout << ans << endl;
    }

    return 0; 
}
