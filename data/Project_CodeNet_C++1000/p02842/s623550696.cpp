#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int result;
  bool flag = false;
  for (int i = N; i > 0; i--) {
  	int tmp = i * 1.08;
    if (tmp == N) {
      flag = true;
      result = i;
      break;
    } else if (tmp < N) {
      break;
    }
  }
  if (flag) {
    cout << result << endl;
  } else {
  	cout << ":(" << endl;
  } 
}
