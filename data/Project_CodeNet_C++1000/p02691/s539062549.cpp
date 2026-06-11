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
  vector<int>a(n);
  
  rep(i,n)cin>>a[i];

  map<int,int>ai;
  map<int,int>aj;
  rep(i,n){
    ai[a[i]+i]++;
    aj[i-a[i]]++;
  }
  int ans=0;
  for(auto&& x : ai){
    int key,value;
    key=x.first;
    value=x.second;
    ans+=aj[key]*value;
  }
  cout<<ans;
}
