#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define m0(x) memset(x, 0, sizeof(x))
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i = 0; i < (n); i++)
#define asort(x) sort(all(x));
#define dsort(x, t) sort(x.begin(), x.end(), greater<t>());
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define MINS(m, s) m.insert(make_pair(s, 1));
#define MFIN(m, s) m.find(s) != m.end()
const int mod = 1000000007;

vector<ll> divisor(ll n) {
    vector<ll> res;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            if(i * i != n) {
                res.push_back(n / i);
            }
        }
    }
    sort(begin(res), end(res));
    return res;
}

int main() {
    ll n, min_ = LLONG_MAX;
    cin >> n;
    vector<ll> v = divisor(n);
    ll len = max(v.size() / 2, v.size() + 1 / 2);
    for(ll i = 0; i < len; i++) {
        min_ = min(min_, v[i] + v[len - i - 1] - 2);
    }

    cout << min_ << endl;

    return 0;
}