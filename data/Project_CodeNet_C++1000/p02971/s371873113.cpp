#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    B[i] = A[i];
  }

  sort(B.rbegin(), B.rend());
  int first = B[0], second = B[1];

  for(int i = 0; i < N; i++) {
    if(A[i] == first) {
      cout << second << endl;
    }
    else {
      cout << first << endl;
    }
  }

  return 0;
}
