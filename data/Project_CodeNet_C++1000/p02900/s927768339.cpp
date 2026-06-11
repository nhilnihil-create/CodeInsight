#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
using ll = long long;
template <class T>
using Grid = vector<vector<T>>;
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
vector<pair<ll, ll>> prime_fact(ll n) {
    vector<pair<ll, ll>> v;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i != 0)
            continue;
        ll cnt = 0;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        v.emplace_back(i, cnt);
    }
    if (n != 1)
        v.emplace_back(n, 1);
    return v;
}
int main(){
    ll A, B;
    cin >> A >> B;
    ll x = gcd(A, B);
    const auto &v = prime_fact(x);
    cout << v.size() + 1 << endl;
}