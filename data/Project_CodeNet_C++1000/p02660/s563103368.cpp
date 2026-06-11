#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;
const int mod = 1e9 + 7;

map<ll, ll> prime_factor(ll n){
    map<ll, ll> res;
    for (ll i = 2; i * i <= n; ++i) {
        while(n % i == 0){
            res[i]++;
            n /= i;
        }
    }
    if(n != 1) res[n] = 1;
    return res;
}

int main(){
    ll n;
    cin >> n;
    map<ll, ll> mp = prime_factor(n);

    ll res = 0;
    for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
        ll num = iter->second;
        ll tmp = 0;
        while(1){
            if (tmp * (tmp + 1) <= 2 * num && 2 * num < (tmp + 1) * (tmp + 2)){
                res += tmp;
                break;
            }
            tmp++;
        }
    }
    cout << res << endl;
}
