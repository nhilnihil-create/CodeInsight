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
  int n,m;
  cin>>n>>m;
  int ans=0;
  vector<vector<int>>b(100001,vector<int>(0));
  priority_queue<int>kouho;
  //b[i]はi日かかるバイトの報酬一覧
  rep(i,n){
    int ta,tb;
    cin>>ta>>tb;
    b[ta].push_back(tb);
  }

  for(int yuuyo=1; yuuyo<=m; yuuyo++){
    rep(i,b[yuuyo].size())kouho.push(b[yuuyo][i]);
    if(kouho.size()){
    int t=0;
    t=kouho.top();
    kouho.pop();
    ans+=t;
    }
  }
    cout<<ans<<endl;
  }
