#include<bits/stdc++.h>

using namespace std;

using ll = long long;



int main(){
  int N;
  cin >> N;
  
  for(int i=2; i<10; i++){
    if((N%i==0 && N/i<10) || N==1){
      cout << "Yes" << endl;
      return 0;
    } 
  }
  
  cout << "No" << endl;
    
  return 0;
}