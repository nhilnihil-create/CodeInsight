#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S,T;
  cin>>S>>T;
  bool K=true;
  for(int X=0;X<S.size();X++){
    if(S[X]!=T[X]){
      K=false;
    }
  }
  if(K==true){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}