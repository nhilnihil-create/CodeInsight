#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n,k;
  cin>>n>>k;
  vector<ll> a(n);
  int ma=0;
  rep(i,n){
    int A; cin>>A;
    a[i]=A;
    ma=max(ma,A);
  }
  int ng=0, ok=ma;
  while(ok-ng>1){
    ll mid=(ok+ng)/2;
    ll cnt=0;
    rep(i,n){
      cnt+=(a[i]+mid-1)/mid-1;
    }
    if(cnt<=k) ok=mid;
    else ng=mid;
  }
  cout<<ok<<endl;
}
