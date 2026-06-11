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
  int n,x,y;
  cin>>n>>x>>y;
  vector<int>ans(n);
  for(int s=1;s<=n-1;s++){
    for(int e=s+1;e<=n;e++){
      int t=min(e-s,abs(s-x)+abs(e-y)+1);
      ans[t]++;
    }
  }
  for(int i=1;i<n;i++){
    cout<<ans[i]<<endl;
  }
}
