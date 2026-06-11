#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B,C,D;
  string S;
  cin>>N>>A>>B>>C>>D;
  cin>>S;
  bool flag=0;
  for (int i=A;i<(max(C,D));i++){
    //cout<<S.at(i)<<" "<<flag<<endl;
    if(S.at(i)=='#'){
      if(flag){
        cout<<"No"<<endl;
        return 0;
      }
      flag=1;
    }
    else{
      //cout<<"##"<<endl;
      flag=0;
    }
  }
  int cnt=0;
  if(C>D){
    for (int i=B-2;i<=D-2;i++){
      if((S.at(i)=='.')&&(S.at(i+1)=='.')&&(S.at(i+2)=='.')){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
  return 0;
}

    
    
  
  
  
    