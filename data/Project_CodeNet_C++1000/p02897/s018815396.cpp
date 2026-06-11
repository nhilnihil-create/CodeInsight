#include <bits/stdc++.h>
using namespace std;


int main() {
  double n;
  
  cin >> n;
  
  double flag = 0;
  
  
  for(int i=1; i<=n; i++){
    if(i%2 == 1)
      flag++;
  }
  
  double pro = flag/n;
  
  cout << pro;
  
  
  
}
