#include <bits/stdc++.h>
using namespace std;

int main() {
    int A,B;
    cin >> A >> B;
  int K =(A+B)/2;
  
  if (A%2==B%2) {
    cout << K << endl;
  }
  else{
    cout << "IMPOSSIBLE" << endl;
  }
}
