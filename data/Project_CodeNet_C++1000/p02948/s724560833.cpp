#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
const long double PI = acos(-1.0L);
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

int n, m;

int main() {
    cin >> n >> m;
    vector< vector<ll> > reward(m+1);
    for(int i = 0; i < n; ++i) {
        ll a, b; cin >> a >> b;
        if(a <= m) reward.at(m-a).emplace_back(b);
    }

    priority_queue<ll> pque;
    ll ans = 0;
    for(int i = m; i >= 0; --i) {
        for(auto x : reward[i]) pque.push(x);
        if(!pque.empty()) {
            ans += pque.top();
            pque.pop();
        }
    }
    cout << ans << endl;
}