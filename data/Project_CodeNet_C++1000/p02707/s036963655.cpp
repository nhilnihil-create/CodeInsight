#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int>A(N);
  for (int i = 0; i < N-1; i++) {
    cin >> A.at(i);
  }
  
  vector<int>count(N-1,0);
  for (int i = 0; i < N-1; i++) {
    count.at(A.at(i)-1)++;
  }
  
  for (int i = 0; i < N-1; i++) {
    cout << count.at(i) << endl;
  }
  cout << 0 << endl;
}

