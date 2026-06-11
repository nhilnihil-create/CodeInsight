#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,X;
  cin >> N >> X;
  
  vector<int>L(N);
  for (int i = 0; i < N; i++) {
    cin >> L.at(i);
  }
  
  int D = 0;
  int count = 0;
  for (int i = 0; i < N; i++) {
    if (D <= X){
      count++;
    }
    D = D + L.at(i);
    if (i == N-1 && D <= X){
      count++;
    }
  }
  cout << count << endl;
}
    