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
  int n;
  cin>>n;
  int sm[10][10];
  rep(i,10)rep(j,10)sm[i][j]=0;
  for(int i=1;i<=n;i++){
    int a,b,c;
    c=i;
    a=c%10;
    b=a;
    while(c>0){
      b=c%10;
      c/=10;
    }
    sm[a][b]++;
  }
  int ans=0;
  for(int i=1;i<=9;i++){
    for(int j=1;j<=9;j++){
      ans+=sm[i][j]*sm[j][i];
    }
  }
  cout<<ans<<endl;
}
