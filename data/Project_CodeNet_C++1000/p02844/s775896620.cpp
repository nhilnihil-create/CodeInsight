#include <bits/stdc++.h>
using namespace std;

int ctoi(char c) {
	switch (c) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return 0;
	}
}

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<vector<int>> A(1000, vector<int>(3));
  int c = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        A.at(c).at(0) = i;
        A.at(c).at(1) = j;
        A.at(c).at(2) = k;
        c++;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 1000; i++) {
    int k = 0;
    for (int j = 0; j < N; j++) {
      if (ctoi(S.at(j)) == A.at(i).at(k)) {
        k++;
      }
      if (k == 3) {
        break;
      }
    }
    if (k == 3) {
      ans++;
    }
  }
  cout << ans << endl;
}