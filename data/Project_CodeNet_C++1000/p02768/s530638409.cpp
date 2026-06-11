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
  int a,b;
  cin>>a>>b;
  int ans=modpow(2,n)-1;
  int c1=1,c2=1;
  for(int i=n;i>=n-a+1;i--){
    c1=c1*i%MOD;
  }
  rep(i,a){
    c1=c1*gyaku(i+1)%MOD;
  }
  for(int i=n;i>=n-b+1;i--){
    c2=c2*i%MOD;
  }
  rep(i,b){
    c2=c2*gyaku(i+1)%MOD;
  }
  ans=(ans-c1-c2)%MOD;
  while(ans<0)ans+=MOD;
  cout<<ans<<endl;
}
