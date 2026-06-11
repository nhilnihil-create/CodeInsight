#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  cin >> n;
  int x = 0;
  
  for(int i = 1; i < 10; i++){
    
    if (n % i == 0){
      if (n / i < 10){
       x = x + 1;
      }
    }
  }
  
  if (x > 0){
    cout << "Yes" << endl;
  }
  else{
	cout << "No" << endl;
  }
  
}