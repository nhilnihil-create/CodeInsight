#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  N--;
  if(N%2 == 1){
    N--;
  }
  cout << N/2 << endl;
}
