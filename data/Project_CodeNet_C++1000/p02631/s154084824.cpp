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
  vector<int>bit(34);
  rep(i,n){
    int t=a[i];
    int b=0;
    while(t>0){
      if(t&1)bit[b]++;
      t/=2;
      b++;
    }
  }
  rep(i,n){
    int t=a[i];
    int b=0;
    int ans=0;
    while(b<34){
      int others1=bit[b];
      if(t&1){others1--;}
      if(others1%2==1)ans+=pow(2,b);
      t/=2;
      b++;
    }
    cout<<ans<<' ';
  }
  }
