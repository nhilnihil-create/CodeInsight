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
  string s;
  cin >> s;
  vector<int> dp(n+1,-1);
  dp[n]=0;
  queue<int> q;
  q.push(0);
  drep(i,n){
    while(1){
      if(q.empty()){
        cout << -1 << endl;
        return 0;
      }
      if(q.front()!=-1&&q.size()<=m)break;
      q.pop();
    }
    if(s[i]=='0')dp[i]=q.front()+1;
    q.push(dp[i]);
  }
  //rep(i,n+1)cout << dp[i] << endl;
  int c = dp[0];
  vector<int> mn(c+1,INF);
  rep(i,n+1){
    if(dp[i]==-1)continue;
    chmin(mn[dp[i]],i);
  }
  drep(i,c){
    cout << mn[i]-mn[i+1] << " ";
  }
  cout << endl;
  return 0;
}