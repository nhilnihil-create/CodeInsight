#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t l,r;cin>>l>>r;
  int64_t ans=2020;
  if(r-l>2023){
    cout <<0<<endl;
    return 0;
  }
  else{
    for(int64_t i=l;i<=r-1;i++){
      for(int64_t j=i+1;j<=r;j++){
        ans=min(ans,(i*j)%2019);
      }
    }
  }
  cout <<ans<<endl;
}