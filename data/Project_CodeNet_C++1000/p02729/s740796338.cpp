#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n, m;
  cin >> n >> m;
  
  int a = 0;
  int b = 0;
  
  if(n >= 2){
    
    a = (n * (n - 1)) / 2;
  }
  
  if(m >= 2){
    b = (m * (m - 1)) / 2;
  }
  
  int total = a + b;
  cout << total << endl;
 
}

