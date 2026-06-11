#include<iostream>
using namespace std;



main(){

  long long int n,i;
  long  long int out;

  

  cin >> n;
  out = 1;
  for(i=n;i>0;i--){
    
    out *= i;

  }

  cout << out << endl;

  return 0;
  
}