#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <cmath>
#include <iomanip>
#include <functional>

#define MOD (1000000007)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> tup;
const int MAX = 510000;

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
    ll N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    vector<bool> RL(N, false);
    vector<bool> LR(N, false);
    ll RLCount = 0, LRCount = 0, LastR = 0, FirstL = 0, LastL = 0, FirstR=0;
    ll current_happiness = 0;
    for(int i = 1; i < N; i++) {
        if(S[i] == S[i-1]) current_happiness++;
        if(S[i] == 'L' && S[i-1] == 'R') {
            RL[i-1] = true;
            RLCount++;
        }
        if(S[i] == 'R' && S[i-1] == 'L') {
            LR[i-1] = true;
            LRCount++;
        }
    }
    if(S[N-1] == 'R') LastR=1;
    else LastL = 1;
    if(S[0] == 'L') FirstL=1;
    else FirstR = 1;

    ll firstSwap = min(K, min(LRCount, RLCount));
    current_happiness += firstSwap * 2;

    if(K-firstSwap > 0) {
        current_happiness += max(min(RLCount - firstSwap, LastL + FirstR), min(LRCount - firstSwap, LastR + FirstL));
    }

    //cout << current_happiness << "," << LRCount << "," << RLCount << endl;
    //cout << current_happiness + min(K, min(LRCount, RLCount)) * 2 + min({LastR + FirstL ,LRCount - min(LRCount, RLCount), K - min(LRCount, RLCount)});
    cout << current_happiness << endl;

    return 0;    
}

