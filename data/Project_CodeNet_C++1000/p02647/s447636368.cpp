#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  int n,k;
  cin>>n>>k;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  rep(i,min(k,100)){
    vector<int> b(n);
    rep(j,n){
      int l=max(j-a[j],0);
      int r=j+a[j];
      b[l]++;
      if(r+1<n) b[r+1]--;
    }
    rep(j,n-1){
      b[j+1]=b[j]+b[j+1];
    }
    a=b;
  }
  rep(i,n) cout<<a[i]<<" ";
  cout<<endl;
}