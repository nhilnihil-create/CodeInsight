#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  
  for (int i = 0; i < S.size(); i=i+1) {
    if (S[i] != T[i]) {
      cout<< "No";
      return 0;
    }
  }
  
  cout << "Yes";
	return 0;
}
