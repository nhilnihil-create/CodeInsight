#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  bool ans=false;
  while(N>0){
    int X=N%10;
    if(X==7){
      ans=true;
      break;
    }
    N/=10;
  }
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
