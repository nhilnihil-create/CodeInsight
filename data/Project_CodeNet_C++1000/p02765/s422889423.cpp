#include<iostream>
using namespace std;

int main() {
  int N, R;
  cin >> N >> R;
  int R_2;
  
  if (N >= 10) {
    cout << R;
  }
  else {
    R_2 = R + 100 * (10 - N);
    cout << R_2;
  }
}