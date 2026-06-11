#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define SZ(x) ((int)(x).size())
#define rep(i,n) for(int i=0;i<(n);++i)
#define fore(i,a) for(auto &i:a)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define answer cout << ans << endl;
signed _main(); signed main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> using v = vector<T>;
template<class T> using vv = vector<v<T>>;
const int MOD=998244353;
const long long INF = 1LL << 60;

//// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

signed _main(){
  int N; cin >> N;
  int max=0,ans=1;
  v<int> D(N);
  v<int> num(100000+10,0);
  rep(i,N){
    cin >> D[i];
    if(i!=0 && D[i]==0){
      cout << 0 << endl;
      return 0;
    }
    num[D[i]]++;
    chmax(max,D[i]);
  }
  if(D[0]!=0){
    cout << 0 << endl;
    return 0;
  }
  for(int i=1;i<max;i++){
    ans = ans * modpow(num[i],num[i+1],MOD) % MOD;
  }
  cout << ans << endl;
  return 0;
}
