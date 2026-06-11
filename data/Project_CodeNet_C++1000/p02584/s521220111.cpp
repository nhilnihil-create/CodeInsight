#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int X, K, D ;
  cin >> X >> K >> D ;
  X = abs(X);
  if(X / D > K) cout << X - K * D << endl;
  else {
    K -= X / D;
    if(K % 2 == 0) cout << X % D << endl;
    else cout << abs(X % D - D);
  }
}
