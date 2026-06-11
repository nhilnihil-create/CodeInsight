#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  bool x = true;
  for(int i=0;i<50000;i++){
    if(floor(i*1.08) == N){
      cout << i << endl;
      x = false;
      break;
    }
  }
    if(x)
      cout << ":(" << endl;
      
}
