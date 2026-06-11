#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  
  cin >> N;
  
  vector<int> l;
  
  for (int i = 0; i < N; i++) {
    int v;
    
    cin >> v;
    
    l.push_back(v);
  }
  
  sort(l.begin(), l.end());
  
  long long sum = 0, tmp = 1;
  
  sum += l[0] + l[1];
  
  for (int i = 2; i < N; i++) {
    tmp *= 2;
    sum += tmp * l[i];
  }
  
  cout << (double)sum / (2.0 * tmp) << endl;
  
  return 0;
}