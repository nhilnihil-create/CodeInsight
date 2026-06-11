#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);++i)
#define fi first
#define se second
#define INF 1000000009
#define lINF 1000000000000000009
typedef long long ll;

int main(){
  int n,m;
  string s;
  cin>>n>>m>>s;

  vector<int>dp(n+1,INF);
  queue<int>que;
  dp[n]=0;
  que.push(0);
  for(int i=n-1;i>=0;i--){
    while(1){
      if(que.empty()){
        cout<<-1<<endl;
        return(0);
      }
      else if(que.front()!=INF&&que.size()<=m){
        break;
      }
      que.pop();
    }
    if(s[i]=='0')dp[i]=que.front()+1;
    que.push(dp[i]);
  }

  vector<int>ans;
  int rest=dp[0],x=0;
  while(x<n){
    rest--;
    int i=1;
    while(rest!=dp[x+i])i++;
    ans.push_back(i);
    x+=i;
  }

  rep(i,ans.size()){
    cout<<ans[i];
    if(i+1==ans.size())cout<<endl;
    else cout<<' ';
  }

  return(0);
}
