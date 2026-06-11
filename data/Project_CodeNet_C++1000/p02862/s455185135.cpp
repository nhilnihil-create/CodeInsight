#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000
int MOD=1000000007;
int modpow(int a,int x){
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
signed main() {
  int x,y,a,b;
  cin>>a>>b;
  x=(2*b-a)/3;
  y=(2*a-b)/3;
  if((a+b)%3!=0||x<0||y<0){cout<<0<<endl;exit(0);}
  int ans=1;
  rep(i,x+y){
    ans=ans*(i+1)%MOD;
  }
  rep(i,x){
    ans=ans*gyaku(i+1)%MOD;
  }
  rep(i,y){
    ans=ans*gyaku(i+1)%MOD;
  }
  cout<<ans<<endl;
}
