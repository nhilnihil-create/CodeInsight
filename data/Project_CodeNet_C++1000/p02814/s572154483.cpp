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
int n,m;

int halflcm(int aa,int bb){
  int counta=0,countb=0;
  int a=aa,b=bb;
  while(a%2==0){
    a/=2;
    counta++;
  }
  while(b%2==0){
    b/=2;
    countb++;
  }
  if(counta==countb)return lcm(aa,bb)/2;
  return m+1;
}
signed main() {
  
  cin>>n>>m;
  vector<int>a(n);
  rep(i,n)cin>>a[i];
  int kousa=a[0],minhalflcm=a[0]/2;
  rep(i,n-1){
    kousa=lcm(kousa,a[i+1]);
    minhalflcm=halflcm(minhalflcm*2,a[i+1]);
    if(minhalflcm>m){cout<<0<<endl;exit(0);}
  }
  if(m>=minhalflcm)cout<<(m-minhalflcm)/kousa+1<<endl;
  else cout<<0<<endl;
}
