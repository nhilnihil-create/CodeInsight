#include<bits/stdc++.h>

using namespace std;

int main(void){
  long long X, Y, Z, W;
  long long S;
  cin >> S;
  X = 1000000000LL;
  W = (S + X - 1LL) / X;
  Y = X * W - S;
  Z = 1LL;
  cout << 0 << " " << 0 << " " << X << " " << Y << " " << Z << " " << W << endl;
  return 0;
}
