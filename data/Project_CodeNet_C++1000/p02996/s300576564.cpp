#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 510000;
const int MOD = 1000000007;

/*long long fac[MAX], finv[MAX], inv[MAX];

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
}*/

int main() {
  ll N;
  cin >> N;

 vector<pair<ll, ll>> v;
  for(int i = 0; i < N; i++) {
      ll a, b;
      cin >> a >> b;
      a *= -1;
      v.push_back({b, a});
    }


   
   sort(v.begin(), v.end());
    ll time = 0;
   for(auto i : v) {
       time += (i.second) * (-1);
       if(time > (i.first)) { cout << "No"; return 0; }

       //cout << i.first * (-1) << " " << i.second * (-1) << endl;
   }
    cout << "Yes";
    return 0;
}