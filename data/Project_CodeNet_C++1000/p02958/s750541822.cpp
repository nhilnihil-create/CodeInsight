#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> V(N);
  for (int i = 0; i < N; i++)
    cin >> V.at(i);
  
  vector<int> W(N);
  for (int j = 0; j < N; j++)
    W.at(j) = V.at(j);
  
  sort(W.begin(),W.end());
  int count = 0;
  
  for (int k = 0; k < N; k++) {
    if (W.at(k) != V.at(k))
      count++;
  }
  if (count <= 2) 
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  
}