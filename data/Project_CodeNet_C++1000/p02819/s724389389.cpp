#include<bits/stdc++.h>
using namespace std;
int main(){
int x;
cin>>x;
int ans;
  while(true){
    int cnt=0;
    for(int i=1; i<=x; i++){
      if(x%i==0) cnt++;
    }
    if(cnt==2) {
      ans=x;
      break;
    }
    else {
      x++;
    }
  }
  cout<<ans<<endl;
}