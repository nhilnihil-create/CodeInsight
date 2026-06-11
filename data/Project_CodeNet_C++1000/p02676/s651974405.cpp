#include <bits/stdc++.h>
using namespace std;
int main() {
  
int K;
  cin>>K;

 string S;
  cin>>S;
  
  for(int i =0; i<K; i++){
  if(S.size()>K)
   cout<<S.at(i);
  } 
  if(S.size()>K)
  cout<<"...";
  
  else if(S.size()<=K)
  cout<<S;
  
 
}
