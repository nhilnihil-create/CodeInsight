#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long double> a(n);
  
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
  }
  
  for(int i = 0; i < n; i++){
    a.at(i) = 1.0/a.at(i);
  }
  
  long double sum = 0;
  
  for(int i = 0; i < n; i++){
    sum += a.at(i);
  }
  
  cout << (long double)1/sum << endl;
  
}