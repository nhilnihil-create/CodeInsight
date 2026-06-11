#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main() {long long int X;cin >> X;
            bool C = 0;
  for(int A = -200; A < 200; A++){
  for(int B = -200; B < 200; B++){
  if(pow(A, 5) - pow(B, 5) == X)
  {cout << A << " " << B;C = 1;}
}if(C)break;
}
}