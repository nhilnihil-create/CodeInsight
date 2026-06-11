#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,M;
  cin >> A >> B >> M;
  
  vector<int> a(A);
  for (int i = 0; i < A; i++) {
    cin >> a.at(i);
  }
  
  vector<int> b(B);
  for (int i = 0; i < B; i++) {
    cin >> b.at(i);
  }
  
  vector<int> x(M);
  vector<int> y(M);
  vector<int> c(M);
  for (int i = 0; i < M; i++) {
    cin >> x.at(i) >> y.at(i) >> c.at(i);
  }
  
  vector<int> z(M);
  for (int i = 0; i < M; i++) {
    z.at(i) = a.at(x.at(i)-1) + b.at(y.at(i)-1) - c.at(i);
  }
  
  sort(z.begin(), z.end());
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  
  if (z.at(0) < a.at(0) + b.at(0)){
    cout << z.at(0) << endl;
  }
  else {
    cout << a.at(0) + b.at(0) << endl;
  }
}
  
  
  
 