#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>
#define int ll

int n,m,k;
vector<ll> ra,rb;

bool isOK(int i,int j){
  if(ra[i]+rb[j]<=k) return true;
  else return false;
}

int nibutan(int i){
  int ok=-1, ng=m+1;
  while(ng-ok>1){
    int middle=(ok+ng)/2;
    if(isOK(i,middle)) ok=middle;
    else ng=middle;
  }
  return i+ok;
}

main(){
  cin>>n>>m>>k;
  ra.resize(n+1);
  rb.resize(m+1);
  ra[0]=0;rb[0]=0;
  rep(i,n){
    int a;
    cin>>a;
    ra[i+1]=ra[i]+a;
  }
  rep(i,m){
    int b;
    cin>>b;
    rb[i+1]=rb[i]+b;
  }
  int ans=0;
  for(int i=0; i<=n; i++){
    if(ra[i]>k) continue;
    int now = nibutan(i);
    ans=max(ans,now);
  }
  cout<<ans<<endl;
}

