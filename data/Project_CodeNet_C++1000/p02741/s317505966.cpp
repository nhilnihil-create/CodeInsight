#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  
  cin >> k;
  
  if (k == 1||k == 2||k == 3||k == 5||k == 7||k == 11||k == 13||k == 15||k == 17||k == 19||k == 23||k == 29||k == 31){
    cout << 1 << endl;
    
  }
  else if (k == 28||k == 30){
      cout << 4 << endl;
  }
  else if (k == 8||k == 12||k == 18||k == 20||k == 27){
      cout << 5 << endl;
  }
  else if (k == 16){
      cout << 14 << endl;
  }
  else if (k == 24){
      cout << 15 << endl;
  }
  else if (k == 32){
      cout << 51 << endl;
  }
  else { 
    cout << 2 << endl;
       }
}

