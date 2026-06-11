#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  int x=S.size();
  
  for(int i=0;i<x;i++){
    if(S.at(i)=='?')
      S.at(i)='D';
  }
  
  cout<<S<<endl;
}
