#include<iostream>
using namespace std;

int N, H[100010];

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> H[i];
  int min_h = 2e+9; bool p = true;
  for (int i = N-1; i >= 0; i--) {
    int dif = max(0, H[i] - min_h);
    if (dif > 1) { p = false; break; }
    min_h = H[i] - dif;
  }
  cout << (p ? "Yes" : "No") << endl;
}