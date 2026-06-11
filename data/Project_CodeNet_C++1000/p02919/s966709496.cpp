#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();


int main() {
    int n;
    cin >> n;
    vector<ll> arr(n+2, 1e6);
    unordered_map<ll, int> pos;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    set<ll> tree = {{0, n+1}};
    ll ans = 0;
    for(ll val = n; val >= 1; val--) {
        ll p = pos[val];
        auto it = tree.lower_bound(p);
        if (*it != n+1) { // next & next^2 larger
            ans += val * (*next(it) - *it) * (p-*prev(it));
        }
        if (*prev(it) != 0) { // prev & prev^2 larger
            ans += val * (*prev(it)-*prev(prev(it))) * (*it-p);
        }
        tree.insert(p);
    }
    cout << ans << endl;
    return 0;
}


