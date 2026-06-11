#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
int main() {
  int n,m,k,bi,cnt=0;
  cin>>n>>m>>k;
  bi=m;
  vector<ll> a(n+1,0),b(m+1,0);
  rep(i,n){
    cin>>a[i+1];
    a[i+1]+=a[i];
  }
  rep(i,m){
    cin>>b[i+1];
    b[i+1]+=b[i];
  }
  rep(i,n+1){
    if(a[i]>k){
      break;
    }
    while(a[i]+b[bi]>k){
      bi--;
    }
    cnt=max(cnt,i+bi);
  }
  cout<<cnt;
}