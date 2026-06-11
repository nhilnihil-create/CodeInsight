#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>=n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;


int main(){
  string s;
  cin >> s;
  int n = s.size();
  vector<int>ans(n);
  int cnt = 0;
  rep(i, 0, n){
      if(s[i]=='R')cnt++;
      else{
          ans[i-1] += cnt/2 + cnt%2;
          ans[i] += cnt/2;
          cnt = 0;
      }
  }
  cnt = 0;
  rrep(i, n-1, 0){
      if(s[i]=='L')cnt++;
      else{
          ans[i+1] += cnt/2 + cnt%2;
          ans[i] += cnt/2;
          cnt = 0;
      }
  }
  rep(i, 0, n)cout << ans[i] << " ";
  cout << endl;
}