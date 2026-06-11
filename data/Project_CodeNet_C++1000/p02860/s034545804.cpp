#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string S,T;
  cin>>N>>S;
  if(N%2!=0){
    cout<<"No"<<endl;
  }
  else{
    T=S.substr(0,N/2);
    if(T==S.substr(N/2,N/2)){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
}
       
    