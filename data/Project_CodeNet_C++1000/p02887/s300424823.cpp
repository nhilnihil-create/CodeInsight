#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<char> S(N);
  int x=0, y;
  
  for(int i=0; i<N; i++) {
    cin >> S[i];
    if(S[i] == y && i != 0)
      x++;
    y = S[i];
  }
  
  for(int l=0; l<x; l++) {
    S.pop_back();
  }
  
  cout << S.size() << endl;    
      
}