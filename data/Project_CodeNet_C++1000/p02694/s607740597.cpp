#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
using iii = pair<ii, ll>;
#define vt vector
#define pq priority_queue
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define __lcm(a, b) a * b / __gcd(a, b)
// #define multicase
const ll MOD = 1e6;
const ll INF = 2e9;
// const ll N = ;

ll need, now, cur;

void solve() {
    ll T = 1;
  #ifdef multicase
    cin >> T;
  #endif
    while(T--) {
        cin >> need;
        now = 100, cur = 0;
        while(now < need) {
            now += now / 100;
            cur++;
        }
        cout << cur << "\n";
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    
}