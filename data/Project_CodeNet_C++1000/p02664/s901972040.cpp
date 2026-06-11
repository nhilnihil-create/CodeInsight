#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  int N=S.size();
  for(int i=0;i<N;i++){
    if(S.at(i)=='?'){
      S.at(i)='D';
    }
  }    
  for(int i=0;i<N;i++){
    cout<<S.at(i);
  }
  cout<<endl;
      
}