#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll INF=1e18;
    
int main(){
  int n,r;
  cin>>n>>r;
  int ans;
  if(n>=10) {ans=r;}
  else{ ans=r+100*(10-n);}
  
  
  cout<<ans<<endl;
  return 0;
}