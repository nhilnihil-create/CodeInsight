#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int>d(N);
  for (int i = 0; i < N; i++) {
    cin >> d.at(i);
  }
  
  int count = 0;
  for (int i = 0; i < N-1; i++) {
    for (int j = i+1; j < N; j++) {
      count += d.at(i)*d.at(j);
    }
  }
  cout << count << endl;
}