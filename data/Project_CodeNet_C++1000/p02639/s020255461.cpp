#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int x[4];
  int a;

  for(int i =0; i < 5; i++){
    cin >> x[i];
  }

  for(int i =0; i < 5; i++){
    if (x[i] == 0) {
        a = i;
     }
  }

  cout << a+1 << endl;
}