#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N;
  
  if(N%2 == 0) cout << 0.5 << endl;
  else cout << (double)(N/2 + 1) / N << endl;
  
}