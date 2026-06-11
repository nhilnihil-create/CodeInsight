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


int main() {
  int n;
  cin >> n;
  vector<string>a(n);
  vector<ll>b;
  set<string>ans;
  ll cnt=0;
  rep(i, 0, n)cin >> a[i],sort(a[i].begin(),a[i].end());
  sort(a.begin(),a.end());
  b.push_back(1);
  rep(i, 1, n){
      if(a[i]==a[i-1])b.back()++;
      else b.push_back(1);
  }
  sort(b.begin(),b.end(),greater<ll>());
  rep(i, 0, b.size()){
      if(b[i]>1)cnt += (b[i]*(b[i]-1)/2);
  }
  cout << cnt << endl;
}