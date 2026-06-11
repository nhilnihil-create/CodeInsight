#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, X;
  cin >> N >> X;
  vector<int> L(N+1);
  for(int i = 0; i < N + 1; i++){
    cin >> L.at(i);
  }
  int i = 1;
  int D = 0;
  while(D <= X && i <= N+1){
    D += L.at(i - 1);
    i++;
    
  }
  cout << i - 1 << endl;
}