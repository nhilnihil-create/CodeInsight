#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  
  int k = S.size();
  
  if(k%2 != 0) cout << "No" << endl;
  else {
    for(int i = 0; i < k/2; i++) {
      if(S.at(i) != S.at(i + k/2)) {
        cout << "No" << endl;
        break;
      }
      else if(i == k/2 - 1) cout << "Yes" << endl;
    }
  }  
  
}