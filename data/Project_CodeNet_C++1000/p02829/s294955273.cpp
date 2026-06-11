#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int a,b;
  cin >> a >> b;
  int total = 0;
  for(int i = 1; i < 4; i++){
    if(a == i || b ==  i) total += i;
  }
  
  if(total == 3) cout << 3 << endl;
  else if(total == 4) cout << 2 << endl;
  else if(total == 5) cout << 1 << endl;

}

