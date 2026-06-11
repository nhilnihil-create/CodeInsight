#include<bits/stdc++.h>
using namespace std ; 

int main () {
  string S ; 
  cin >> S ; 
  
  if (S.at(0) == 'S'){
    cout << "Cloudy" << endl ; 
  }
  
  else if (S.at(0) == 'C'){
    cout << "Rainy" << endl ; 
  }
  else {
    cout << "Sunny" << endl ; 
  }
  
}