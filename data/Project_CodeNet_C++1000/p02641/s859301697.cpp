#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, N;
  cin >> X >> N;
  vector<int> V(N);
  for (int i=0; i<N; i++) {
    cin >> V.at(i);
  }
  
  int m=101, mi=0, s=0, cont;
  for (int i=101; i>=-1; i--) {
    
    cont=0;
    for (int j=0; j<N; j++) {
      if (V.at(j) == i) {
        cont = 1;
        break;
      }
    }
    if (cont == 1) {continue;}
    
    if (i > X) {
      s = i - X;
    }
    else {
      s = X - i;
    }
    
    if (s < m) {
      m = s;
      mi = i;
    }
    else if (s == m) {
      mi = min(mi, i);
    }
    //cout << mi << endl;
  }
  cout << mi << endl;
  
}