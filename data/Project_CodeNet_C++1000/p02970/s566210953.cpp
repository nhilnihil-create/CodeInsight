#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int N,D;
  cin>>N>>D;
  int tit;
  tit=2*D+1;
  int ans;
  if(N%tit==0){
    ans=N/tit;
  }
  else{
    ans=N/tit+1;
  }
  cout<<ans<<endl;
}