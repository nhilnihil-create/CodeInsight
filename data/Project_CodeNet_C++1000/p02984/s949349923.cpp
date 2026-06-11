#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  int n;
  cin>>n;
  vector<ll> a(n),ans(n);
  ll ans0=0;
  rep(i,n){
    cin>>a[i];
    if(i%2==0) ans0+=a[i];
    else ans0-=a[i];
  }
  ans[0]=ans0/2;
  for(int i=1; i<n; i++){
    ans[i]=a[i-1]-ans[i-1];
  }
  rep(i,n) cout<<ans[i]*2<<endl;
}