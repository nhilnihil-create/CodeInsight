#include <bits/stdc++.h> 
using namespace std;

int main(){
  
  int a,b,c = 0,d = 0;
  cin >> a >> b;
  
  for(int i=0; i<=a; i++){
    
    c += i-1;
    
  }
  
  for(int i=0; i<=b; i++){
    
    d += i-1;
    
  }
    
    cout << c+d+2 << endl;
  
}
