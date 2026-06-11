#include <iostream>

using namespace std;

int main(){
  long long S;
  long long X1 = 0, Y1 = 0, X2 = 1000000000, Y2 = 1, X3, Y3;
  cin >> S;

  Y3 = S / X2;
  if (S%X2 != 0) Y3++;
  X3 = X2 * Y3 - S;

  printf("%llu %llu %llu %llu %llu %llu\n",X1,Y1,X2,Y2,X3,Y3);
}
