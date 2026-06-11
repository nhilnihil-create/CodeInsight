#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
int INF=100100100100100;

int a[2010];
int zen[2010];
int po[2010];

int add(int a,int b){
  return (a+b)%MOD;
}
int prod(int a,int b){
  return (a*b)%MOD;
}
    
signed main(){
  int n,k;
  cin>>n>>k;
  rep(i,n)cin>>a[i];
  rep(i,n){
    rep(j,n){
      if(a[j]<a[i])zen[i]++;
    }
  }
  rep(i,n){
    for(int j=i+1;j<n;j++){
      if(a[j]<a[i])po[i]++;
    }
  }
  int ans=0;
  rep(i,n){
    int m=prod(zen[i],(k*(k-1)/2)%MOD);
    ans=add(ans,add(prod(po[i],k),m));
  }
  cout<<ans<<endl;
  return 0;
}