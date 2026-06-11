#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  if (N <= 2) {
    cout << 0 << endl;
  }
  else {
    cout << (N-1)/2 << endl;
  }
}