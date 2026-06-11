#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b; cin>>a>>b;
  if(a==1 && b==1){
    cout<<1000000<<endl;
  }else{
    int ans=0;
    if(a==1 || b==1){
      ans+=300000;
    }if(a==2){
      ans+=200000;
    }if(b==2){
      ans+=200000;
    }if(a==3){
      ans+=100000;
    }if(b==3){
      ans+=100000;
    }
    cout<<ans<<endl;
  }
}