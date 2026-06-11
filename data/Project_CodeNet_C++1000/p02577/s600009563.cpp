#include <bits/stdc++.h>
using namespace std;

int main() {
  string N;
  cin >> N;
 
  int amari = 0;
  
  for(int i =0;i < N.size(); i++){
    amari += N.at(i)-3;
  }
  amari = amari % 9;
    
    
  if(amari % 9 == 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
  
}
