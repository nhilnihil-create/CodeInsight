#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

ll const mod = 1e9+7;


int main() {
  int N,a;
  ll cnt = 1;
  cin >> N;
  vector<int> memo(N,0);
  rep(i,N) {
    cin >> a;
    if (a==0) cnt *= (3-memo[a]);
    else  cnt = (cnt*(memo[a-1] - memo[a]))%mod;
    memo[a]++;
  }
  cout << cnt << endl;
}