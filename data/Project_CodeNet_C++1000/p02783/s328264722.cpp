#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, A;
  cin >> H >> A;
  
  for (int i=1 ; ; i++){
    if (H <= A*i){
      cout << i << endl;
      break;
    }
  }
}