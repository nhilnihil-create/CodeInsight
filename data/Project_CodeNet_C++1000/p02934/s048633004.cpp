#include <bits/stdc++.h>
using namespace std;

int main() {
  long double N;
  cin >> N;
  vector<long double> V(N);
  for (int i = 0; i < N; i++)
    cin >> V.at(i);
  
  long double k = 0;
  for (int j = 0; j < N; j++)
    k += 1/V.at(j);
  
  cout << fixed << setprecision(16);
  cout << 1/k << endl;
}
  
