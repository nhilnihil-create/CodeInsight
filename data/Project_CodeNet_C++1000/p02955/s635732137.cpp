#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

vector<ll> find_fac(ll x) {
    vector<ll> ans;
    for(ll i = 1; i*i <= x; i++) {
        if (x % i == 0) {
            ans.push_back(i);
            if (i*i != x)
                ans.push_back(x/i);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
bool can_use(vector<ll> arr, ll x, ll quota) {
    vector<ll> rem;
    for(ll val: arr) {
        if (val % x > 0)
            rem.push_back(val%x);
    }
    sort(rem.begin(), rem.end());
    int l = 0, r = rem.size()-1;
    while (l <= r) {
        ll m = min(rem[l], x-rem[r]);
        quota -= m;
        rem[l] -= m;
        rem[r] += m;
        if (rem[l] % x == 0)
            l++;
        if (rem[r] % x == 0)
            r--;
    }
    return quota >= 0;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n, 0);
    for(auto& val: arr)
        cin >> val;
    ll acc = accumulate(arr.begin(), arr.end(), 0LL);
    auto cand = find_fac(acc);
    ll ans = 1;
    for(ll val: cand) {
        if (can_use(arr, val, k)) {
            ans = val;
        }
    }
    cout << ans << endl;
    return 0;
}


