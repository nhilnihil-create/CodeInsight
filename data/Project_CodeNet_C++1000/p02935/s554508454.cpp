#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v.at(i);
  }
  
  sort(v.begin(), v.end());
  double a =  (double)((v.at(0) + v.at(1)) * 1.0/ 2);
  
  for (int i = 2; i < N; i++) {
    a = (a + v.at(i)) / 2;
  }
  cout << a << endl;
}

  
    
    
 


