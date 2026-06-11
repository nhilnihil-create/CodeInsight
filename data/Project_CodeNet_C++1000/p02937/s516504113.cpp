#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <cmath>
#include <iomanip>
#include <set>
#include <functional>

#define MOD (1000000007)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> tup;
const int MAX = 3000000;

long long fac[MAX], finv[MAX], inv[MAX];


ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
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
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

map<ll,ll> prime;//素因数分解でそれぞれの素数がいくつ出てきたかを保存するmap

//O(√n)
//整列済み(mapはkeyで自動で整列される)
void prime_factorize(ll n){
    if(n<=1) return;
    ll l=sqrt(n);
   for(ll i=2;i<=(ll)(l);i++) { //
        if(n%i==0){
            prime_factorize(i);prime_factorize(ll(n/i));return;
        }
    }
    //mapでは存在しないkeyの場合も自動で構築される
    prime[n]++;return;
} 


int main() {
    string s,t;
    cin >> s;
    cin >> t;

    vector<ll> dp(t.size(), 0);

    map<char, vector<ll>> m;
    for(ll i = 0; i < s.size(); i++) {
        m[s[i]].push_back(i);
    }

    for(ll i = 0; i < t.size(); i++) {
        if(m[t[i]].size() == 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    dp[0] = m[t[0]][0];
    // cout << dp[0] << endl;
    for(ll i = 1; i < t.size(); i++) {
        auto itr = upper_bound(m[t[i]].begin(), m[t[i]].end(), dp[i-1] % s.size());
        if(itr != m[t[i]].end()) {
            dp[i] = dp[i-1] -  (dp[i-1] % s.size()) + *itr;
            // cout << "found: plus -> " <<   -  (dp[i-1] % s.size()) + *itr << endl;
        }
        else {
            dp[i] = dp[i-1] +  (s.size() - dp[i-1] % s.size()) + m[t[i]][0];
            // cout << "not found: plus -> " <<  (s.size() - dp[i-1] % s.size()) + m[t[i]][0] << endl;
        }
    }

    cout << dp[t.size()-1] + 1 << endl;

    return 0;    
}


