#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<cassert>
#include<numeric>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
const int INF = 1001001001;
const long long LINF = 1001002003004005006ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> p(n),c(n);
  rep(i,n)cin >> p[i];
  rep(i,n)cin >> c[i];
  rep(i,n)p[i]--;
  ll ans = -LINF;
  rep(si,n){
    vector<int> v;
    int pos = p[si];
    ll tot = 0;
    while(true){
      v.push_back(c[pos]);
      tot+=c[pos];
      pos = p[pos];
      if(pos==p[si])break;
    }
    int l = v.size();
    ll res = 0;
    rep(i,l){
      if(i+1>k)break;
      res += v[i];
      if(tot>0)chmax(ans,res+tot*((k-(i+1))/l));
      else chmax(ans,res);
    }
  }
  cout << ans << endl;
}