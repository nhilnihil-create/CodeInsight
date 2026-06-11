#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

template<class T>
vector<T> get_divisor(T n) {
    vector<T> res;
    for (long long i = 1; (i * i) <= n; i++) {
        if (n % i != 0) continue;
        res.push_back(i);
        if ((i * i) != n) res.push_back(n / i);
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n;
    cin >> n;
    set<ll> ans;
    {
        vector<ll> tmp = get_divisor(n);
        rep(i, sz(tmp)) {
            if (tmp[i] == 1) continue;
            ll cv = n;
            while(cv % tmp[i] == 0) cv /= tmp[i];
            cv %= tmp[i];
            if (cv == 1) ans.insert(tmp[i]);
        }
    }
    {
        vector<ll> tmp = get_divisor(n - 1);
        rep(i, sz(tmp)) ans.insert(tmp[i]);
    }
    ans.erase(1);
    cout << sz(ans) << endl;
    return 0;
}
