#include <bits/stdc++.h>
using namespace std;

int main() {
  int M,D,count=0;
  cin >> M >> D;
  
  while(M>=1) {
    while(D>=22) {
      int d1 = D %10;
      int d10 = D /10 %10;
      if(M >= d1 * d10 && d1 >=2 && d10 >=2) count++;
      D -=1;
    }
    M -=1;
  }
  cout << count << endl;
}