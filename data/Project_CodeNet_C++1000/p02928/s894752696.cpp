#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  long long n,k;
  cin >> n >> k;
  long long u[n];
  rep(i,n)cin >> u[i];
  long long p=1000000007;
  long long r[n];
  long long m[n];
  rep(i,n){
    r[i]=0;
    m[i]=0;
  }
  rep(i,n){
    long long h=u[i];
    for(int j=i+1;j<n;j++){
      if(u[j]<h){
        r[j]++;
        m[j]++;
      }
    }
    rep(j,i){
      if(u[j]<h){
        m[j]++;
      }
    }
  }
  long long ans=0;
  rep(i,n){
    ans=(ans+r[i]*k+((k*(k-1)/2)%p)*m[i])%p;
  }
  cout << ans << endl;
}