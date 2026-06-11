#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int n=0;
  for(int i=0; i<B; i++){
    if(A * i - i + 1 >= B)
      break;
  n++;
  }
  
  cout << n << endl;
}

