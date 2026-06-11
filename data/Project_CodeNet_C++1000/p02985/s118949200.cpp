#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}


ll const mod = 1e9+7;
// べき乗
int64_t modpow(int64_t x, int64_t n) {
    x = x%mod;
    if(n==0) return 1;  //再帰の終了条件

    else if(n%2==1) {
        return (x*modpow(x, n-1))%mod;  //nが奇数ならnを1ずらす
    }
    else return modpow((x*x)%mod, n/2)%mod;  //nが偶数ならnが半分になる
}

//逆元　a/b の modをとるとき -> a*modinv(b)%mod
long long modinv(long long a, long long m = 1e9+7) {
  long long b = m, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m; 
  if (u < 0) u += m;
  return u;
}

int main() {
  int N,K,a,b;
  cin >> N >> K;
  vector<vector<int>> tree(N);
  rep(i,N-1){
    cin >> a >> b;
    a--;b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  ll res=K;
  vector<bool> vd(N,false);
  queue<int> q;
  q.push(0);
  vd[0]=true;
  while (!q.empty()) {
    auto t = q.front();
    q.pop();
    int cnt=2;
    if (t==0) cnt--;
    for (auto c:tree[t]) {
      if (vd[c]==false) {
        res *= K-cnt;
        res%=mod;
        cnt++;
        q.push(c);
        vd[c] = true;
      }
    }
  }
  cout << res << endl;
}