#include <bits/stdc++.h>
using namespace std;

int main() {
  double A,B;
  cin >> A >> B;
  for(int i=1; i<=1100; i += 1){
    int X = i*8/100;
    int Y = i*10/100;
    if(X == A && Y == B){
      cout << i << endl;
      return 0;
    }
  }
cout << -1 << endl;
}
