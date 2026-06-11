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
  vector<int>aa(n);
  rep(i,n){cin>>a[i];aa[i]=a[i];}
  vector<int>bit(61);
  rep(i,n){
    int count=0;
    while(a[i]>0){
      if(a[i]&1)bit[count]++;
      a[i]/=2;
      count++;
    }
  }
  int ans=0;
  rep(i,n){
    int count=0;
    while(aa[i]>0){
      if(aa[i]&1)ans=(modpow(2,count)*(n-bit[count])%MOD+ans)%MOD;
      aa[i]/=2;
      count++;
    }
  }
  cout<<ans;
}
