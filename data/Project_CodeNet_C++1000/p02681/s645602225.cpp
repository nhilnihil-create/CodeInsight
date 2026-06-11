#include <bits/stdc++.h>
using namespace std;

int main(){
 string S,T;
  cin>>S>>T;
  int s=(int)S.size();
  int t=(int)T.size();
  bool ans =true;
  for(int i=0;i<s;i++){
    
  if(t!=s+1){
    cout<<"No"<<endl;
    ans =false;
    break;
  }
    if(S.at(i)!=T.at(i)){
      cout<<"No"<<endl;
      ans =false;
      break;
    }
  }
  if(ans){
    cout<<"Yes"<<endl;
  }
}