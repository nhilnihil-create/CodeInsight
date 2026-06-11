#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  string a, b, S;
  cin >> a >> b;
  
  for (int i = 0; i < N; i++) {
    char c_a = a.at(i);
    char c_b = b.at(i);
    S = S + c_a + c_b;
  }
  cout << S << endl;
}