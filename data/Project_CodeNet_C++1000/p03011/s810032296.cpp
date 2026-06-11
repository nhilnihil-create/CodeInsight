#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C,X,Y,Z;
  cin >> A >> B >> C;
  X = A+B;
  Y = B + C;
  Z = A + C;
   cout << min({X,Y,Z});
  
}