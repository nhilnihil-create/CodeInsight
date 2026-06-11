#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin >> N >> K;
  int count = 1;
  
  if (N == 1){
    cout << 1 << endl;
    return 0;
  }
  
  while (N/K >= 1){
    N = N/K ;
    count++;
  }
  cout << count << endl;
}