#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  ll n;
  cin>>n;
  ll a[n-1],b[n-1];
  rep(i,0,n-1) cin>>a[i]>>b[i];
  ll ans=(n+2)*(n+1)*n/6;
  rep(i,0,n-1){
    if(a[i]>b[i]) swap(a[i],b[i]);
    ans-=a[i]*(n+1-b[i]);
  }
  cout<<ans<<endl;
}