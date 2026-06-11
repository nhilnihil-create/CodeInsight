#include <bits/stdc++.h> 
using namespace std; 
 
int main() {
  int n;
  float answer;
  cin >> n;
  if(n % 2 == 0) 
    answer = (float)n / (2 * n);
  else
    answer = (float)(n + 1) / (2 * n);
  
  cout << answer;
  return 0;
}