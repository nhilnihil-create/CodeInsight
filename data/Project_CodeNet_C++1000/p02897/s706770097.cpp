#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  cin >> n;
  int total = 0;
  for(int i = 1; i <= n; i++){
    if(i % 2 == 0){
      total++;
    }
  }
  double p, q;
  p = total;
  q = n;
  double r = p / q;
  double e = 1 - r;
  cout << fixed << setprecision(10) << e << endl;
}