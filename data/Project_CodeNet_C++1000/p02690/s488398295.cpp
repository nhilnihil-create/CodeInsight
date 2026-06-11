#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define ld long double
#define oo 2e18
#define OS tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define file freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
map<ll, int> p;
set<ll> s;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (ll i = -6208; i <= 6208; i++) {
        s.insert(i * i * i * i * i);
        p[i * i * i * i * i] = i;
    }
    for (ll i = -6208; i <= 6208; i++) {
        if (((n >= 0 && LLONG_MAX - n >= i * i * i * i * i) ||
             (n < 0 && abs(LLONG_MIN - n) >= abs(i * i * i * i * i))) &&
            s.find(n + i * i * i * i * i) != s.end()) {
            cout << p[n + i * i * i * i * i] << " " << i;
            return 0;
        }
    }
    return 0;
}