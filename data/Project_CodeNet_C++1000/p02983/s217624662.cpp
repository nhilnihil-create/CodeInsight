#include<bits/stdc++.h>
using namespace std;
int main() {
  int l,r,lm,rm,ans=2019,i,j;
  cin>>l>>r;
  if(r-l+1>=2019) cout<<0<<endl;
  else{
    lm=l%2019;
    rm=r%2019;
    if(rm<=lm) cout<<0<<endl;
    else if(rm-lm+1>=673) cout<<0<<endl;
    else{
      for(i=lm;i<rm;i++){
        for(j=i+1;j<=rm;j++){
          if(i*j%2019<ans) ans=i*j%2019;
        }
      }
      cout<<ans<<endl;
    }
  }
}