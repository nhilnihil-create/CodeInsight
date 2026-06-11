#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> d(N);
  for (int i = 0; i < N; i++) {
    cin >> d[i];
  }
  int count = 0;
  
  /*for (int i = 1; i < N; i++) {
    count += d[0] * d[i];
  }
  for (int i = 2; i < N; i++) {
    count += d[1] * d[i];
  }*/
  int n = 0;
  for (int n = 0;n < N - 1; n++) {  
    for (int i = n + 1; i < N; i++) {
      count += d[n] * d[i];
    }
  }
  
 cout << count << endl;     
}
 

