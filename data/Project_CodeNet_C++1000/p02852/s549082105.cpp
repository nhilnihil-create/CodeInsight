#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
 
const int mx=200010;
const ll mod=1e9+7;

int main(){
  int n,m;
  string s;
  cin >> n >> m >> s;
  vector<int> dp(mx,inf);
  dp[n] = 0;
  queue<int> q;
  q.push(0);
  for(int i=n-1; i>=0; i--){
    while(1){
      if(q.size()==0){
        cout << -1 << endl; return 0;
      }
      if(q.front()!=inf && q.size()<=m) break;
      q.pop();
    }
    if(s[i]=='0') dp[i]=q.front()+1;
    q.push(dp[i]);
  }

  vector<int> ans;
  int x = 0;
  int cnt = dp[0];
  while(x<n){
    cnt--;
    int i=1;
    while(dp[x+i]!=cnt) i++;
    ans.push_back(i);
    x += i;
  }
  for(auto it:ans){
    cout << it << " ";
  }
  cout << endl;
  return 0;
}