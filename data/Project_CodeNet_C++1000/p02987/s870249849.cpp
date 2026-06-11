#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin>>S;
  map<char,int>mp;
  vector<int>A(0);
  for(int X=0;X<S.size();X++){
    mp[S[X]]++;
  }
  for(auto p:mp){
    auto V=p.second;
    A.push_back(V);
  }
  if(A.size()==2&&A[0]==2&&A[1]==2){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
