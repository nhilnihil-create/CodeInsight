#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> P(n), Q(n), A(n), B(n); 
  for (int i = 0; i < n; i++) cin >> P.at(i);
  for (int i = 0; i < n; i++) cin >> Q.at(i);
  for (int i = 0; i < n; i++) A.at(i) = i + 1;
  
  int count = 0, x = 0, y = 0;
  do {
    count++;
    for (int i = 0; i < n; i++) B.at(i) = A.at(i);
    if (B == P) x = count;
    if (B == Q) y = count;
  } while(next_permutation(A.begin(), A.end()));

  cout << abs(x - y) << endl;
}