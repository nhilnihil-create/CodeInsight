#include <bits/stdc++.h>
using namespace std; 
    
int main(){
  int N,A;
  cin >> N;
  A=N%10;
  if(A==3){
    cout << "bon" << endl;
  }
  else if(A==0 || A==1 || A==6 || A==8){
    cout << "pon" << endl;
  }
  else{
    cout << "hon" << endl;
  }
}
  
  