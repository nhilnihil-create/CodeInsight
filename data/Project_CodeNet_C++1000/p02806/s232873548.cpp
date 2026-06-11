#include <bits/stdc++.h>
using namespace std;
 
 
 
int main() {
  int N;
  cin >>N;
  
  
  vector<string> si(N);
  vector<int> ti(N); 
  for(int i=0;i<N;i++){
    cin>>si.at(i)>>ti.at(i);
  }
  
  string X;
  cin>>X;
  
  int index;
  for(int i=0;i<N;i++){
    if(si.at(i)==X){
      index=i;
      break;
    }
  }
 
  int sum=0;
  for(int i=index+1;i<N;i++){
    sum+=ti.at(i);
  }
  
  cout<<sum;
  
  return 0;
}