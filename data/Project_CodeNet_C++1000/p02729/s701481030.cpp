#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  int count=0;
  if (N>1){
    count += N*(N-1)/2;
  }
  if (M>1){
    count += M*(M-1)/2;
  }
  cout << count << endl;
}
