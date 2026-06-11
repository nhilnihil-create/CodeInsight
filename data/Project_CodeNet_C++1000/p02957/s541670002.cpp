#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin >> A >> B;
  if((B-A)%2 == 0){
    cout << (B+A)/2 << endl;
    return 0;
  }
  cout << "IMPOSSIBLE" << endl;
}
