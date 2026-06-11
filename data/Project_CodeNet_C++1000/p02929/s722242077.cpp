/**
 * Created by hiramekun at 20:52 on 2019-08-24.
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
template<typename T> using pq = priority_queue<T>;
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<typename T, typename K> using ump = unordered_map<T, K>;
const ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll mod = 1000000007;
const ll inf = ll(1e9);
const ll e5 = ll(1e5);
const ll ll_inf = ll(1e9) * ll(1e9);

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define each(i, mp) for(auto& i:mp)
#define eb emplace_back
#define F first
#define S second
#define all(obj) (obj).begin(), (obj).end()

template<class T>
ostream &operator<<(ostream &out, const vector<T> &list) {
    ll n = list.size();
    rep(i, n) out << list[i] << ' ';
    return out;
}


template<class T>
istream &operator>>(istream &in, vector<T> &list) {
    ll n = list.size();
    rep(i, n) in >> list[i];
    return in;
}

/* ------------- ANSWER ------------- */
/* ---------------------------------- */
ll factorial(ll n) {
    ll ans = 1;
    while (n > 1) {
        ans *= n;
        ans %= mod;
        n--;
    }
    return ans;
}


void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    n *= 2;

    vector<bool> is_right(n);
    rep(i, n) {
        if (i % 2 == 0 && s[i] == 'W') is_right[i] = true;
        if (i % 2 == 1 && s[i] == 'B') is_right[i] = true;
    }
    ll ans = 1;
    ll left_sum = 0;
    rep(i, n) {
        if (is_right[i]) {
            if (left_sum == 0) {
                cout << 0 << '\n';
                return;
            }
            ans *= left_sum;
            ans %= mod;
            left_sum--;
        } else {
            left_sum++;
        }
    }
    if (left_sum > 0) cout << 0 << '\n';
    else cout << ans * factorial(n / 2) % mod << '\n';
}

int main() {
#ifdef MY_DEBUG
    while (true) {
#endif
        solve();
#ifdef MY_DEBUG
    }
#endif
    return 0;
}