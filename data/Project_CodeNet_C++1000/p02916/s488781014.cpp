#include <math.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define PI 3.14159265358979323846264338327950L
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

int main() {
  int N;
  cin >> N;
  vector<int> A(N + 1);
  vector<int> B(N + 1);
  vector<int> C(N);

  rep(i, N) {
    int a;
    cin >> a;
    A.at(i) = a;
  }
  rep(i, N) {
    int b;
    cin >> b;
    B.at(i) = b;
  }
  rep(i, N - 1) {
    int c;
    cin >> c;
    C.at(i) = c;
  }

  int sum = 0;
  rep(i, N) {
    sum += B.at(A.at(i) - 1);
    if (i != 0 && (A.at(i) - A.at(i - 1)) == 1) {
      sum += C.at(A.at(i) - 2);
    }
  }
  cout << sum << endl;
}
