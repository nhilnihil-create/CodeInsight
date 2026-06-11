#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

typedef long long ll;
const int N = 200;
ll dp[21][N];

ll solve(int n,int sum,int now,vector<int> &in,int veri){
  //cout << n <<" " << now <<" " << sum << " " << veri << endl;
  if (n == now){
    if (sum == veri)return 1;
    else return 0;
  }
  
  ll &ret = dp[sum][now];
  if (ret == -1){
    ret=0;
    if (0<=sum+in[now] && sum+in[now] <= 20){
      ret+=solve(n,sum+in[now],now+1,in,veri);
    }

    if (now != 0 && 0<=sum-in[now] && sum-in[now] <= 20){
      ret+=solve(n,sum-in[now],now+1,in,veri);
    }
  }
  return ret;
}

main(){
  int n;
  while(cin>>n && n){
    rep(i,21)rep(j,N)dp[i][j]=-1;
    vector<int> in(n-1);
    int veri;
    rep(i,n-1)cin>>in[i];
    cin>>veri;
    cout << solve(n-1,0,0,in,veri) << endl;
  }
  return false;
}