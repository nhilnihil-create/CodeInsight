#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin >> x;
  
  int k;
  for(int i=360; i>0; i += 360){
    if(i%x==0){
      k = i/x;
      break;
    }
  }
  
  cout << k << endl;
}