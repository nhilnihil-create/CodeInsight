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
  vector<int>a(n+1), cnt(200200),ans;
  rep(i, 1, n+1)cin >> a[i];
  //reverse(a.begin(),a.end());
  for(int i=n; i>=1; i--){
    int p = 0;
    for(int j=2*i; j<=n; j+=i)if(cnt[j]!=0)p++;
    if(p%2==a[i])continue;
    ans.push_back(i);
    cnt[i] = 1;
  }
  cout << ans.size() << endl;
  rep(i, 0, ans.size()){
    cout << ans[ans.size()-1-i] << " ";
  }
  cout << endl;
}