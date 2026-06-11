#include <bits/stdc++.h>
using namespace std;
 
int main(){ 
  int X;
  cin >> X;
  for (int64_t i = 0; i < 121; i++) {
    for (int64_t j = i; j < 121; j++) {
      if (j * j * j * j * j - i * i * i * i * i  == X) {
        cout << j << " " << i << endl;
        break;
      }
      if (j * j * j * j * j + i * i * i * i * i  == X) {
        cout << j << " " << -i << endl;
        break;
      }
    }
  }
}
  