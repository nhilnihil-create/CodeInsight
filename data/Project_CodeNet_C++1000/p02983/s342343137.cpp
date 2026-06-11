#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int l,r; cin>>l >>r;
  int ans;
  if(r-l>=2018){ans=0;}
  else{
    l%=2019; r%=2019;
    if(l>=r){ans=0;}
    else{
      ans=2019;
      for(int i=l; i<r; i++){
        for(int j=i+1; j<=r; j++){
          int a=(i*j)%2019;
          ans=min(ans,a);
          
        }
      }
    }
  }
  cout<<ans;
}

