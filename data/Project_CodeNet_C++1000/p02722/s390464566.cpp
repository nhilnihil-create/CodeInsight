#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

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

vector<ll> enum_divisors(ll n){
    vector<ll> res;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0){
            res.push_back(i);
            if (n/i != i) res.push_back(n/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main(){
    ll n;
    cin >> n;

    ll res = 1;
    map<ll, ll> mp1 = prime_factor(n-1);
    for(auto x : mp1){
        res *= x.second + 1;
    }
    res--;

    auto v = enum_divisors(n);
    for (int i = 1; i < v.size(); ++i) {
        ll x = n;
        while (x % v[i] == 0){
            x /= v[i];
        }
        if (x % v[i] == 1) res++;
    }

    cout << res << endl;
}