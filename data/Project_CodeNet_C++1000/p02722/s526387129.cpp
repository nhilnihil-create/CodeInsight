#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);
unordered_map<ll, int> get_primes(ll n) {
    unordered_map<ll, int> facs;
    ll n2 = n;
    for(ll i = 2; i*i <= n; i++) {
        while (n2 % i == 0) {
            facs[i] += 1;
            n2 /= i;
        }
    }
    if (n2 > 1)
        facs[n2] += 1;
    return facs;
}

vector<ll> get_facs(unordered_map<ll, int>& primes) {
    vector<ll> nums, cnt;
    for(auto p: primes) {
        nums.push_back(p.first);
        cnt.push_back(p.second);
    }
    vector<ll> ans;
    auto dfs = [&] (auto self, int d, ll cur) -> void {
        if (d == nums.size()) {
            ans.push_back(cur);
            return;
        }
        ll pre_mul = 1;
        for(int i = 0; i <= cnt[d]; i++) {
            self(self, d+1, cur*pre_mul);
            pre_mul *= nums[d];
        }
    };
    dfs(dfs, 0, 1);
    return ans;
}
int main() {
    //3140 = 2 * 2 * 5 * 157 => 3x2x2 = 11
    // 3141 = 3*3*349, backtracing: 3, 3141
    ll n; cin >> n;
    unordered_set<ll> ans;
    auto tmp = get_primes(n-1);
    for(ll num: get_facs(tmp)) {
        ans.insert(num);
        // cout << num << endl;
    }
    auto tmp2 = get_primes(n);
    auto facs = get_facs(tmp2);
    for(ll cand: facs) {
        if(cand == 1) continue;
        ll n2 = n;
        while(n2 % cand == 0) {
            n2 /= cand;
        }
        if (n2 % cand == 1) {
            ans.insert(cand);
        }
    }
    ans.erase(1);
    cout << ans.size() << endl;
    return 0;
}


