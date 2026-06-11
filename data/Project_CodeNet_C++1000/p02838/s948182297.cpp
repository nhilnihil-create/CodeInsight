#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define reps(i,n) for (int i=1;i<=(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rreps(i,n) for (int i=(n);i>0;i--)
#define all(v) (v).begin(),(v).end()
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>
template<class T> inline bool chmin(T &a, T b) {if (a>b) {a = b; return 1;} return 0;};
template<class T> inline bool chmax(T &a, T b) {if (a<b) {a = b; return 1;} return 0;};
typedef long long int ll;
const long long INF = 1LL << 60;

// a^n mod を計算する, O(log(n))
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
  int N; cin >> N;
  ll c[60][2] = {};
  rep(i,N) {
    ll A; cin >> A;
    bitset<60> s(A);
    rep(j,60) c[j][s.test(j)]++;
  }
  ll MOD = 1000000007;

  ll ans = 0;
  rep(i,60){
    ll comb = c[i][0]*c[i][1]%MOD;
    (ans += comb*modpow(2,i,MOD)%MOD) %= MOD;
  }
  cout << ans << endl;


  // cout << fixed << setprecision(10);
  
  return 0;
}