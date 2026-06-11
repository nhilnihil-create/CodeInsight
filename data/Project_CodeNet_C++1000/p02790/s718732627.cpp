#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int a,b;
  cin >> a >> b;
  if (a < b){
  for (int i =0; i < b; i++){
    cout << a;
    }
  }
  else {
  for (int j = 0; j < a; j++) {
    cout << b;
    }
  }
}
