#include <bits/stdc++.h>
#include <math.h>
#include <cmath>
using namespace std;
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
 
int main(){
  int n;
  cin>>n;
  
  ll ans=0;
  for(int i=1;i<=n;i++){
    ans+=1ll*i*(n/i)*((n/i)+1)/2;
  }
  
  cout<<ans<<endl;
  return 0;
}