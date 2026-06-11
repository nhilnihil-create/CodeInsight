#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)
#define mod 1000000007
ll n,k,h[310];
ll f[310][310];
int main(){
  cin>>n>>k;
  k=n-k;
  for(int i=0;i<310;i++)for(int j=0;j<310;j++)f[i][j]=1e17;
  f[0][0]=0,h[0]=0;
  for(int i=1;i<=n;i++){
      cin>>h[i];
      for(int j=0;j<=n;j++){
	  for(int r=0;r<i;r++){
	      if(j)chmin(f[i][j],f[r][j-1]+abs(h[i]-h[r]));
	  }
      }
  }
  ll ans=1e17;
  for(int i=0;i<=n;i++)for(int j=k;j<=n;j++){
      chmin(ans,f[i][j]+h[i]);
  }
  cout<<ans/2<<endl;
  return 0;
}
