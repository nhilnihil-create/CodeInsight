#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  cin >> n;
  int two = 0;
  int num = 0;
  
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    if(x % 2 == 0){
      two++;
      if(x % 3 == 0){
        num++;
      }
      else if(x % 5 == 0){
        num++;
      }
    }
  }
  
  if(two == num){
    cout << "APPROVED" << endl;
  }
  else{
    cout << "DENIED" << endl;
  }
  
 
  
  

}

