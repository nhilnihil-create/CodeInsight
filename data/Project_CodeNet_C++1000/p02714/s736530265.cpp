#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>

#define MOD (1000000007)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> tup;
const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

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


int main() {
    COMinit();

    ll N;
    cin >> N;
    string S;
    cin >> S;

    map<char, vector<int> > m;
    m['R'] = vector<int>();
    m['G'] = vector<int>();
    m['B'] = vector<int>();
    for(int i = 0;i < S.size(); i++) {
        m[S[i]].push_back(i);
    }


    ll not_match = 0;
    for(int diff = 1; diff <= (S.size() - 1)/2; diff++) {
        for(int j = 0;; j++) {
            if(j+ 2*diff >= S.size()) break;
            if(S[j] != S[j+diff] && S[j] != S[j+2*diff] && S[j+diff] != S[j+2*diff]) not_match++;
        }
    }

    cout << m['R'].size() * m['G'].size() * m['B'].size()  - not_match << endl;

    return 0;
}