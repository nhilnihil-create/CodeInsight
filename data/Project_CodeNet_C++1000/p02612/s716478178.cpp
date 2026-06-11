#include<bits/stdc++.h>
using namespace std;
int main(){
  int t,answer;
  bool a=false;
  cin>>t;
  for(int i=0; i<11;i++){
    if(t==1000*i) a=true;
    else if(t>1000*i) answer=1000*(i+1)-t;
  }
  if(a) cout<<0<<endl;
  else cout<<answer<<endl;
}
