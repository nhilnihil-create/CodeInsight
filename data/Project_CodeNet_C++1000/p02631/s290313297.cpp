#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  cin >> N;
  vector<int>a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  bitset<30>C;
  bitset<30>A(a.at(0));
  for (int i = 1; i < N; i++) {
    bitset<30>B(a.at(i));
    C = A ^ B;
    A = C;
  }
  
  for (int i = 0; i < N; i++) {
    bitset<30>D(a.at(i));
    D ^= C;
    int E = D.to_ullong();
    cout << E << endl;
  }
}