#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  
  int plug = 1;
  for (int i=0 ; ; i++){
    if (plug >= b){
      cout << i << endl;
      break;
    }
    plug += a-1;
  }
}