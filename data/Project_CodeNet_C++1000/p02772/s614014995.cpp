#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  scanf ("%d", &N);
  vector<int> paper(N);
  for(int i=0; i<N; i++){
    cin >> paper[i];
  }
  
  bool can = true;
  
  for(int i=0; i<N; i++){
    if( paper[i] %2 ==0){
      if( paper[i] %3 != 0 && paper[i] %5 != 0){
        can = false;
        break;
      }
    }
  }
  
  if( can == true ) cout << "APPROVED" << endl;
  else cout << "DENIED" << endl;

}