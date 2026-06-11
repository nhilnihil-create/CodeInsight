#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

const int MAX = 30;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

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

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  COMinit();

  ll N;
  cin >> N;
  ll len = 1;
  for(int i = 0; i < N; i++){
    len *= 2;
  }

  vector<ll> S(len);
  for(int i = 0; i < len; i++){
    cin >> S[i];
  }

  sort(S.begin(), S.end(), greater<ll>());

  bool ans = true;

  vector<int> gen(len);
  vector<int> pre_gen(len);

  pre_gen[0] = 1;
  gen[0] = 1;
  ll cnt = 1;
  for(int i = 0; i < N; i++){

    ll loc = 0;
    ll tmp_cnt = 0;
    for(int j = 0; j < len; j++){
      
      if(pre_gen[j] && tmp_cnt < cnt){
        
        while(loc < len){

          if(!gen[loc] && S[j] > S[loc]){
            gen[loc] = 1;
            loc++;
            tmp_cnt++;
            break;
          }
          loc++;
        }
      }
    }

    pre_gen = gen;
    if(tmp_cnt != cnt){
      ans = false;
    }

    cnt *= 2;

  }

  if(ans){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

  return 0;
}
