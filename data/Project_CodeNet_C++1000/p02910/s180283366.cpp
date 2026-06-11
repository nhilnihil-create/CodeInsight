#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int size = S.size();
  bool flag = true;
  for (int i = 0; i < size; i++) {
  	if ((i + 1) % 2 == 0 && (S[i] == 'L' || S[i] == 'U' || S[i] == 'D')) {
    } else if ((i + 1) % 2 == 1 && (S[i] == 'R' || S[i] == 'U' || S[i] == 'D')) {
    } else {
    	flag = false;
        break;
    }
  }
  if (flag) {
  	cout << "Yes" << endl;
  } else {
  	cout << "No" << endl;
  }
}
