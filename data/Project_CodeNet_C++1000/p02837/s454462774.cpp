#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000

int MOD=1000000007;
int modpow(int a,int x){
  if(a<0)a+=MOD;
  int ans=1;
  while(x>0){
    if(x&1) ans=ans*a%MOD;
      a=a*a%MOD;
      x>>=1;
  }
  return ans;
}

int gyaku(int n){
    return modpow(n,MOD-2);
}
////////////////////////////////////////////////////////////
signed main() {
  int n;
  cin>>n;
  vector<vector<int>>x(n,vector<int>(0));
  vector<vector<int>>y(n,vector<int>(0));
  rep(i,n){
    int t;
    cin>>t;
    rep(j,t){
      int tx,ty;
      cin>>tx>>ty;
      tx--;
      x[i].push_back(tx);
      y[i].push_back(ty);
    }
  }
  int ans=0;
  for(int bit=0;bit<(1<<n);++bit){
    int count=0;
    int tb=bit;
    while(tb>0){
      if(tb&1)count++;
      tb/=2;
    }
    bool b=1;
    rep(i,n){
      if(bit&(1<<i)){
      rep(j,x[i].size()){
        if(bit&(1<<x[i][j]) && y[i][j]==0){b=0;}
        if(!(bit&(1<<x[i][j])) && y[i][j]==1){b=0;}
      }
    }
  }
    if(b){ans=max(ans,count);}
  }
  cout<<ans<<endl;
}
