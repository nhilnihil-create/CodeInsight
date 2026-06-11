#include<bits/stdc++.h>
using namespace std;

int main(){
  int X;cin>>X;
  int ans=0;
  while(true){
    ans++;
    if(X*ans%360==0) break;
  }
  cout<<ans<<endl;
}