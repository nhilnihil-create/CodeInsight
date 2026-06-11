#include <bits/stdc++.h>
using namespace std;

int main(){
  int L{}, R{}, d{};

  int cuenta = 0;

  cin >> L >> R >> d;
  
  while (L != R+1){
    if(L % d == 0){
      ++cuenta;
    }
    L++;
  }

  cout << cuenta << endl;
  return 0;
}
