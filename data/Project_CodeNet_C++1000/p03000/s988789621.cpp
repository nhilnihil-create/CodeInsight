#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,X,bound=0; cin >> N >> X;
  int D[N+1];
  D[0]=0;
  
  for(int i=0; i<N; i++) {
    int x; cin >> x;
    D[i+1] = D[i] + x;
  }
  for(int i =0; i<= N; i++) if(D[i] <= X) bound++;
  
  cout << bound << endl;
}