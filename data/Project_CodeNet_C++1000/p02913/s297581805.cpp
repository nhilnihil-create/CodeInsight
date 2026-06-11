#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const int N = 5e3 + 5, p1 = 31, p2 = 51, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
int n, ans, p[N], q[N], invp[N], invq[N];
vector<pair<pair<int, int>, int> >len[N];
string s;
struct Rubin_karp {
    pair<int, int> h[N];
    int add(int a, int b, int mod) {
        return (a + b) % mod;
    }
    int sub(int a, int b, int mod) {
        return (((a - b) % mod) + mod) % mod;
    }
    int mul(int a, int b, int mod) {
        return (1ll * a * b) % mod;
    }
    pair<int, int> add(pair<int, int> a, pair<int, int> b) {
        return {add(a.first, b.first, mod1), add(a.second, b.second, mod2)};
    }
    pair<int, int> sub(pair<int, int> a, pair<int, int> b) {
        return {sub(a.first, b.first, mod1), sub(a.second, b.second, mod2)};
    }
    pair<int ,int> mul(pair<int, int> a, pair<int, int> b) {
        return {mul(a.first, b.first, mod1), mul(a.second, b.second, mod2)};
    }
    int fp(int b, int p, int mod) {
        if(!p) return 1;
        int res = fp(b, p / 2, mod);
        res = mul(res, res, mod);
        if(p & 1) res = mul(res, b, mod);
        return res;
    }
    void pre() {
        p[0] = q[0] = invp[0] = invq[0] = 1;
        int inv_p = fp(p1, mod1 - 2, mod1), inv_q = fp(p2, mod2 - 2, mod2);
        for(int i = 1; i < N; i++){
            p[i] = mul(p[i - 1], p1, mod1), invp[i] = mul(invp[i - 1], inv_p, mod1);
            q[i] = mul(q[i - 1], p2, mod2), invq[i] = mul(invq[i - 1], inv_q, mod2);
        }
    }
    pair<int, int> Hash(int idx, int pos, char let, pair<int, int> cur_hash) {
        return {add(cur_hash.first, mul(let, p[pos], mod1), mod1), add(cur_hash.second, mul(let, q[pos], mod2), mod2)};
    }
    pair<int, int> Hash_all(string &s) {
        pair<int, int> hv = {0, 0};
        for(int i = 0; i < s.size(); i++)
            hv = this-> Hash(i, i, s[i], hv), this->h[i] = hv;
        return hv;
    }
    pair<int, int> get_hash(int l, int r) {
        if(l > r) swap(l, r);
        if(!l) return this-> h[r];
        return mul(sub(h[r], h[l - 1]), {invp[l], invq[l]});
    }
}rks;
bool ok(int idx){
    if(len[idx].empty()) return 0;
    sort(len[idx].begin(), len[idx].end());
    pair<int, int> last_hash;
    int last_idx;
    last_hash = len[idx][0].first;
    last_idx = len[idx][0].second;
    for(int i = 1; i < len[idx].size(); i++){
        if(len[idx][i].first != last_hash)
            last_hash = len[idx][i].first, last_idx = len[idx][i].second;
        else{
            if(abs(len[idx][i].second - last_idx) >= idx)
                return 1;
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> s;
    rks.pre();
    rks.Hash_all(s);
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(j - i + 1 > n / 2) continue;
            pair<int, int>hv = rks.get_hash(i, j);
            len[j - i + 1].push_back({hv, i});
        }
    }
    int s = 1, e = n, mid;
    while(s <= e){
        mid = s + e >> 1;
        if(ok(mid))
            ans = mid, s = mid + 1;
        else
            e = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}
