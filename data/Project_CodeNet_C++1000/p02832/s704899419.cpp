#include <bits/stdc++.h>
using namespace std;

  

int main() {
  int N;
  cin>>N;
  
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  
  int ima=1;
  for(int i=0;i<N;i++){
    if(vec.at(i)==ima) ima+=1;
  }
  
  if(ima==1) cout<<-1<<endl;
  else cout<<N-(ima-1)<<endl;
   

    
}