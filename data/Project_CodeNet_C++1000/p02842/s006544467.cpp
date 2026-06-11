#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int lower, upper; 
  cin >> N;
  lower = ceil(N / 1.08);
  upper = floor((N+1)/1.08 - .001);
  
  if (upper >= lower) cout << lower << endl;
  else cout << ":(" << endl;
}