#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t X;
  cin >> X;
  int64_t N=100;
  int y=0;
  while (N<X){
    N += N/100;
    y++;
  }
  cout << y << endl;
}
