#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  double a = N/2;
  
  cout << fixed << setprecision(10);
  if(N % 2 ==0) cout << a / N << endl;
  else cout << (a+1) /N << endl;
}