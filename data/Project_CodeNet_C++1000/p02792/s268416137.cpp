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
const ll mod = 1000000007;

int main(){
  int n;
  cin >> n;
  vector<vector<int>>cnt(10,vector<int>(10));
  rep(i, 1, n+1){
    string s = to_string(i);
    int m = s.size();
    cnt[s[0]-'0'][s[m-1]-'0']++;
  }
  int ans=0;
  rep(i, 1, 10)rep(j, 1, 10)ans += cnt[i][j]*cnt[j][i];
  cout << ans << endl;
}