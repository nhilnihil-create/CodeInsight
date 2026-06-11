#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int K;
  cin >> K;
  
  if (K == 1 || K == 2 || K == 3 || K == 5 || K == 7 || K == 11 || K == 13 || K == 15 || K == 17 || K == 19 || K == 23 || K == 29 || K == 31){
    cout << 1 << endl;
  }
  else if (K == 4 || K == 6 || K == 9 || K == 10 || K == 14 || K == 21 || K == 22 || K == 25 || K == 26){
    cout << 2 << endl;
  }
  else if (K == 28 || K == 30){
    cout << 4 << endl;
  }
  else if (K == 8 || K == 12 || K == 18 || K == 20 || K == 27){
    cout << 5 << endl;
  }
  else if (K == 16){
    cout << 14 << endl;
  }
  else if (K == 32){
    cout << 51 << endl;
  }
  else {
    cout << 15 << endl;
  }
}