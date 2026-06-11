#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin>>S;
  int k=1;
  bool bo=true;
  for(int i=1;i<S.size();i++){
    if((bo && S[i]==S[i-1]) || (i==S.size()-2 && S[i]==S[i+1])){
      bo=false;
      i++;
    }else
      bo=true;
    k++;
  }
  cout<<k<<endl;
}