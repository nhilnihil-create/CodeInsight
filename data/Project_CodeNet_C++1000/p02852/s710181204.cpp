#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  int n,m;cin>>n>>m;
  string s;cin>>s;
  vector<int>dp(n+1);
  rep(i, n+1)dp[i]=-1;
  dp[0]=0;
  rrep1(i, n){
    if(s[i]=='1')continue;
    rrep1(j, m){
      if(i-j<0 || s[i-j]=='1')continue;
      dp[i]=i-j;
      break;
    }
  }

//  for(auto t: dp)cout<<t<<' ';cout<<endl;

  int c=n;
  vector<int>results;
  while(dp[c]>0){
    results.push_back(c-dp[c]);
    c=dp[c];
//cout<<c<<' ';
  }
  if(dp[c]<0){ cout<<-1<<endl; return 0; }
  results.push_back(c-dp[c]);

//cout<<endl;

  rrep(i, results.size())cout<<results[i]<<' ';cout<<endl;

  return 0;
}
