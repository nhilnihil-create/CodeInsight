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
signed main() {
  int n;
  cin>>n;
  vector<int>a(n);
  int max1=0,max2=0;
  rep(i,n){
    cin>>a[i];
    if(max1<=a[i]){
      max2=max1;
      max1=a[i];
    }
    else if(max1>=a[i]&&max2<a[i]){
      max2=a[i];
    }
  }
  rep(i,n){
    if(a[i]==max1){cout<<max2<<endl;}
    else cout<<max1<<endl;
  }

}
