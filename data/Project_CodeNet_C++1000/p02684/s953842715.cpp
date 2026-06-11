#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 1;i <= n;i++)
using ll = long long;

int main(){
  ll n,k,now=1; cin >>n >>k;
  int a[200001],b[200001];
  rep(i,n) cin >>b[i];
  for(;k>0;k/=2){
    if(k%2) now=b[now];
    rep(i,n) a[i]=b[b[i]];
    rep(i,n) b[i]=a[i];
  }
  cout << now << endl;
  return 0;
}