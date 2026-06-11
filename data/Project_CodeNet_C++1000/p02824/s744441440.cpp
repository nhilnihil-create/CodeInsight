#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,v,p;
  ll m;
  cin>>n>>m>>v>>p;
  ll a[n];
  rep(i,0,n) cin>>a[i];
  sort(a,a+n);
  int b=0;
  int c=n-p;
  while(c>b){
    int d=(b+c)/2;
    int e=upper_bound(a,a+n,a[d]+m)-a;
    if(n-e>=p){
      b=d+1;
    }
    else{
      ll cur=0;
      rep(i,0,n-p+1){
        cur+=min(a[d]+m-a[i],m);
      }
      if(cur-m<m*(v-p)){
        b=d+1;
      }
      else{
        c=d;
      }
    }
  }
  cout<<n-b<<endl;
}