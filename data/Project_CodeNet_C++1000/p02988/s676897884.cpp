#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> V(N);
  for (int i = 0; i < N; i++)
    cin >> V.at(i);
  
  int count = 0;
  for (int j = 1; j < N - 1; j++) {
    if ((V.at(j - 1) < V.at(j) && V.at(j) < V.at(j + 1)) 
        || (V.at(j + 1) < V.at(j) && V.at(j) < V.at(j - 1)))
      count++;
  }
  cout << count << endl;
}
