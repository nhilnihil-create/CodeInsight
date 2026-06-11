#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
using iii = pair<ii, ll>;
#define vt vector
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define __lcm(a, b) a * b / __gcd(a, b)
const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e2 + 5;

ll n, m, temp, ans;
priority_queue<ll> pq;

void solve() {
    cin >> n >> m;
    for(ll i = 1, x; i <= n; i++) {
        cin >> x;
        pq.push(x);
    }
    while(m--) {
        temp = pq.top(); pq.pop();
        pq.push(temp / 2);
    }
    ans = 0;
    while(pq.size()) {
        ans += pq.top(); pq.pop();
    }
    cout << ans << "\n";
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    
}