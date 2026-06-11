#include <bits/stdc++.h> 
using namespace std; 
int main(){
  int N;
  cin>>N;
  for(int r=0; r<9; r++){
    for(int i=0; i<9; i++){
      if((r+1)*(i+1) == N){
         cout << "Yes" << endl;
         return 0;
      }
    }
  }
  
  cout << "No" << endl;
}