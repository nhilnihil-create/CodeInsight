#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; 
  cin >> N;
  vector<int> V(N);
  for (int i = 0; i < N; i++)
    cin >> V.at(i);
  
  int count = 100000;
  for (int j = 0; j < N; j++) {
    int a = 0,b = 0;
    for (int k = 0; k < j + 1; k++)
      a += V.at(k);
    for (int l = j + 1; l < N; l++)
      b += V.at(l);
    if (abs(a - b) < count)
      count = abs(a - b);
  }
  
  cout << count << endl;
    
 
}