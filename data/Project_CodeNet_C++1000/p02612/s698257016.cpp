#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int oturi, number;
  
  for(int i = 0; i * 1000 < N; i++) {
    number = i;
  }
  
  oturi = (number + 1) * 1000 - N;
  cout << oturi << endl;
  
}