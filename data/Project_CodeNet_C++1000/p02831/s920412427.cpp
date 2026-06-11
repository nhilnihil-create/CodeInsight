#include <bits/stdc++.h>
using namespace std;

int main() {

  long long A, B;
  cin >> A >> B;
  
  long long saisho = 1;

  for(int i = 2; i <= min(A, B); i++) {
    if(A%i == 0 && B%i == 0) saisho = i;
  }
  
  long long ans = A*B/saisho;
  
  cout << ans << endl;
  
}