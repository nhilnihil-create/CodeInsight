#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n+1, 0);
    rep(i, n)cin >> a[i];
    rep(i, n)b[i+1] = b[i] + a[i];
    rep(i, n+1){
        b[i] -= i;
        b[i] %= k;
        if(b[i] < 0)(b[i] += k) %= k;
    }
    map<ll, vector<int>> mp;
    rep(i, n+1)mp[b[i]].push_back(i);
    ll ans = 0;
    for(auto& p : mp){
        vector<int> c = p.second;
        if(p.first != 0 && c.size() == 1)continue;
        int sum = 0;
        int idx = 0;
        rep(i, c.size()){
            while(c[i] - c[idx] >= k){
                idx++;
                sum--;
            }
            ans += sum;
            sum++;
        }
    }
    cout << ans << endl;
}