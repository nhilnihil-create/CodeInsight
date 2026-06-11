#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin >> A >> B;
  int M,m;
  M=max(A,B);
  m=min(A,B);
  for(int i=0;i<M;i++){
    cout << m;
  }
  cout << endl;
}
