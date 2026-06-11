#include <bits/stdc++.h>
using namespace std;

int main(){
 
  int N,M;
  cin >> N >> M;
  
  vector<int> A(M);
  int sum=0;
  
  for(int i=0;i<M;i++){
  cin >> A.at(i);
    sum +=A.at(i);
  }
  
  if(N-sum>=0){
   cout << N-sum << endl; 
  }
  else{
   cout << "-1" << endl; 
  }
  }