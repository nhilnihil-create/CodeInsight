#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
  int N;
  cin >> N;
  vector<pair<int, int>> V(N);

  for (int i = 0; i < N; i++) {
    cin >> V.at(i).first;
    V.at(i).second = i+1;
  }
  
  sort(V.begin(), V.end());
  
 
  for (int i = 0; i < N; i++) {
          cout << V.at(i).second << " ";
  }
  cout << endl;
 
}