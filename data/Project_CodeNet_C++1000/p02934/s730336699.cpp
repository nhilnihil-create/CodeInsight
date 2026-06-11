#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  double S=0;
  for(int i=0; i<N; i++){
    double A;
    cin >> A;
    S += 1/A;
  }
  cout << 1/S << endl;
}
