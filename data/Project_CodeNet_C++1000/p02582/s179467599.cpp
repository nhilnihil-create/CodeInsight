#include<bits/stdc++.h>
using namespace std;
int main(){
  string A;
  cin>>A;
  int ans=0;
  int kouho=0;
  for(int i=0; i<A.size(); i++){
    if(A.at(i)=='R'){
      kouho++;
    }
    else{
      ans=max(ans, kouho);
      kouho=0;
    }
  }
  ans=max(ans, kouho);
  cout<<ans<<endl;
}
