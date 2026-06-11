#include<bits/stdc++.h>
using namespace std;
int main(){
int N,K;
  cin>>N>>K;
  string s;
  cin>>s;
  int num=1;
  for(int i=1;i<N;i++){
  if(s.at(i)!=s.at(i-1))
    num+=1;
  }
  if(num-2*K<=1)
    cout<<N-1<<endl;
  else
    cout<<N-(num-2*K)<<endl;
    
  
  
   return 0;
}