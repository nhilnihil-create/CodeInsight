#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int M,D;
  int count = 0;
  cin >> M >> D;
  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= D; j++) {
      if (j%10 >= 2 && j/10 >= 2 && (j%10)*(j/10) == i){
        count++;
      }
    }
  }
  cout << count << endl;
}
  