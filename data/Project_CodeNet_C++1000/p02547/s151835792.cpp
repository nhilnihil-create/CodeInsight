#include<iostream>
using namespace std;
int main () {
  int N;
  cin >> N;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  bool one = a == b;
  bool two = c == d;
  for (int i = 0; i < N - 2; i ++) {
    int k, j;
    cin >> k >> j;
    bool thr = k == j;
    if (one && two && thr) {
      cout << "Yes" << endl;
      return 0;
    }
    one = two;
    two = thr;
  }
  cout << "No" << endl;
}