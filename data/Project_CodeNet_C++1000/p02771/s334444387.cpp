#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int a, b, c;
  cin >> a >> b >> c;
  int count = 0;
  
  for(int i = 1; i <= 9; i++){
    if(i == a) count++;
    if(i == b) count++;
    if(i == c) count++;
    
    if(count == 2){
      cout << "Yes" << endl;
      return 0;
    }
    
    count = 0;
  }
  cout << "No" << endl;
}