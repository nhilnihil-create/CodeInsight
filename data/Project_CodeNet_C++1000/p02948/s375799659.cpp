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
  int n,m;
  cin >> n >> m;
  int a[n],b[n];
  rep(i,n)cin >> a[i] >> b[i];
  vector<int> s[m];
  rep(i,n){
    if(a[i]<=m)s[m-a[i]].push_back(b[i]);
  }
  ll ans = 0;
  priority_queue<int> q;
  drep(i,m){
    for(int x:s[i])q.push(x);
    if(!q.empty()){
      ans += q.top();
      q.pop();
    }
  }
  cout << ans << endl;
}