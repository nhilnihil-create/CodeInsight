#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N,O;
  cin >> N;
  O = N%2;
  N /= 2;
  if(O == 1){
    cout << N +1 <<endl;
    return 0;
  }
  cout << N <<endl;
}