#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl;
// *min_element(c + l, c + r) *max_element(c + l, c + r)
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// struct Edge {
//   int to, id;
//   Edge(int to, int id): to(to), id(id) {}
// };

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
  int N,K;cin>>N>>K;
  vector<ll> num(K+1,0);
  ll ans = 0;
  for (int x = K;x > 0;x--) {
    //    cout << x << endl;
    ll cnt = 0, kind = 1;
    int now = x + x;
    while(now <= K) {
      kind++;
      cnt = (cnt + num[now]) % MOD;
      now += x;
    }
    ll gap = ((modpow(kind,N,MOD) - cnt + MOD) % MOD);
    ans += (gap * x) % MOD;
    ans %= MOD;
    num[x] = gap;
  }
  cout << ans << endl;
}
