#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <cmath>
#include <map>
#include <tuple>
#include <queue>
#include <stack>
#include <iomanip>
#include <list>

#define MOD (1000000007)

using namespace std;

typedef long long ll;

// a^n mod を計算する
ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

const int MAX = 510000;
ll fac[MAX], finv[MAX], inv[MAX];

ll modinv(ll a, ll mod) {
    ll b = mod, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// 負の数にも対応した % 演算
ll mod(ll val, ll m) {
  ll res = val % m;
  if (res < 0) res += m;
  return res;
}

void push_el(queue<tuple<int, int, int>> &q, vector<vector<char>> &v, vector<vector<int>> &seen, int next_h, int next_w, int next_dist, int h, int w) {
    if(next_h < 0 || next_h >= h || next_w < 0 || next_w >= w) return;
    if(seen[next_h][next_w] == true) return;
    if(v[next_h][next_w] != '.') return;
    //cout << "->stacked:" << next_h <<","<<next_w << "=" << next_dist << endl;
    seen[next_h][next_w] = true;
    q.push(make_tuple(next_h, next_w, next_dist));
}

int solve(vector<vector<char>> &v, int start_h, int start_w) {//, int end_h, int end_w) {
    queue<tuple<int, int, int>> q;
    vector<vector<int>> seen(v.size(), vector<int>(v[0].size(), false));

    //if(v[start_h][start_w] != '.') return -1;// || v[end_h][end_w] != '.')  return -1;
    push_el(q, v, seen, start_h, start_w, 0, v.size(), v[0].size());
    int max_dist = 0;
    int count = 0;
    while(q.size() >= 1) {
        tuple<int, int, int> t = q.front(); q.pop();
        int curr_h = get<0>(t);
        int curr_w = get<1>(t);
        int curr_dist = get<2>(t);

        max_dist = max(curr_dist, max_dist);

        //cout << curr_dist << endl;
//        cout << curr_h << "," << curr_w << ":" << curr_dist << endl;

        //if(seen[curr_h][curr_w]) continue;
        //seen[curr_h][curr_w] = true;
        //if(curr_h == end_h && curr_w == end_w) return curr_dist;
        
        push_el(q, v, seen, curr_h, curr_w + 1, curr_dist + 1, v.size(), v[0].size());
        push_el(q, v, seen, curr_h, curr_w - 1, curr_dist + 1, v.size(), v[0].size());
        push_el(q, v, seen, curr_h + 1, curr_w, curr_dist + 1, v.size(), v[0].size());
        push_el(q, v, seen, curr_h - 1, curr_w, curr_dist + 1, v.size(), v[0].size());
    }
    return max_dist;
}

int main() {
    ll N;
    cin >> N;

    map<pair<int,int>, int> m;

    for(int i = 1; i <= N; i++) {
        string s = to_string(i);
        pair<int, int> key = make_pair(s[0], s[s.size()-1]);
        if(m.find(key) == m.end()) m[key] = 1;
        else m[key]++;
    }

    ll ret = 0;
    for(auto itr = m.begin(); itr != m.end(); ++itr) {
        pair<int, int> key = itr->first;
        pair<int, int> key_inv = make_pair(key.second, key.first);
        
        if(m.find(key_inv) != m.end()) ret += m[key] * m[key_inv];
    }

    cout << ret << endl;
    return 0;
}
