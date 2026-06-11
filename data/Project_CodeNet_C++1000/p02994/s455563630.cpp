#include<iostream>
#include<cmath>
using namespace std;

int main() {
  int N, L; cin >> N >> L;
  int sum = 0, min_apple = L;
  for (int i = 0; i < N; i++) {
    sum += L + i;
    if (abs(L + i) < abs(min_apple))
      min_apple = L + i;
  }
  cout << sum - min_apple << endl;
}