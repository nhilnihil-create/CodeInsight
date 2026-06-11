#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  double d;
  double a;
  
  for(int i=0;i<n;i++){
    cin >> a;
    d += 1 / a;
  }
  
  cout << 1 / d << endl;
}
