#include <bits/stdc++.h>
using namespace std;

int main(){
  long long X;
  long long K;
  long long D;
  cin >> X >> K >> D;
  long long N = X/D;
  if(X < 0) X *= -1, N *= -1;
  if(D <= X/K) cout << X-K*D << endl;
  else{
    if((N-K)%2 == 0) cout << X%D << endl;
    else cout << D-X%D << endl;
  }
}