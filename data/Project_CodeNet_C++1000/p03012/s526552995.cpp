#include <bits/stdc++.h>
using namespace std;



int main() {
  int N;
  cin>>N;
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
    
  int mae=0;
  int usi=0;
  for(int i=0;i<N;i++){
    usi+=vec.at(i);
  }
  int dis=100000;
  for(int i=0;i<N;i++){
    mae+=vec.at(i);
    usi-=vec.at(i);
    int sa=abs(mae-usi);
    dis=min(dis,sa);
  }
  cout<<dis<<endl;
      
  
    
 
}