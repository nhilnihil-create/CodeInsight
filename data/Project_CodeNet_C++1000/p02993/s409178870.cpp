#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int size = 4;
  char mae;
  bool flag = true;
  for (int i = 0; i < size; i++) {
  	if (i == 0) {
    	mae = S[i];
    } else {
      if (mae == S[i]) {
      	flag = false;
        break;
      } else {
      	mae = S[i];
      }
    }
  }
  if (flag) {
  	cout << "Good" << endl;
  } else {
    cout << "Bad" << endl;
  }
}