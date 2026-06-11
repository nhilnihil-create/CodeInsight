#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;

int main(){
  ll h,w;
  cin>>h>>w;
  ll ans;
  
  if (h==1 || w==1){
    ans=1;
    
  }else{


 	 ans=(h*w+1)/2;

  }


  cout<<ans<<endl;

}
