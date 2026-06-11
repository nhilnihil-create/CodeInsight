#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  
  cin >> N;
  
  vector<int> l;
  
  for (int i = 0; i < N; i++) {
    int _in;
    
    cin >> _in;
    
    l.push_back(_in);
  }
  
  double u = 0;
  
  for (int i = 0; i < N; i++) {
    u += 1.0 / l[i];
  }
  
  cout << 1.0 / u << endl;
  
  return 0;
}
