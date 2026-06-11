#include <bits/stdc++.h> 
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> V(N);
  for (int i = 0; i < N; i++)
    cin >> V.at(i);
  
  int count = 0;
  for (int j = 0; j < N; j++) {
    for (int k = j + 1; k < N; k++) 
      count += V.at(j)*V.at(k);
  }
  
  cout << count << endl;
    
}
