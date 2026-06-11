#include <bits/stdc++.h>
using namespace std;

  

int main() {
  string S;
  cin>>S;
  
  string A=S;
  reverse(S.begin(),S.end());
  int sum=0;
  for(int i=0;i<S.size()/2;i++){
    if(A.at(i)!=S.at(i)) sum+=1;
  }
  
  cout<<sum<<endl;
  
}
