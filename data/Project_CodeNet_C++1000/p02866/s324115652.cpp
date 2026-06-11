#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod2 = 1000000007;
const ll mod = 998244353;

ll power(int x, int y){
    ll answer = 1;
    lrep(i, 0, y){
        answer *= x;
        answer %= mod;
    }
    return answer;
}
int main(){
  int n;
  cin >> n;
  vector<int>d(n),cnt(100000);
  rep(i, 0, n){
      cin >> d[i];
      cnt[d[i]]++;
  }
  if(d[0]!=0||cnt[0]!=1){
      cout << 0 << endl;
      return 0;
  }
  sort(d.begin(),d.end());
  int p = d[d.size()-1];
  ll ans = 1;
  rep(i, 1, p+1){
      if(cnt[i]==0){
          cout << 0 << endl;
          return 0;
      }
      ans *= power(cnt[i-1], cnt[i]);
      ans %= mod;
  }
  cout << ans << endl;
}