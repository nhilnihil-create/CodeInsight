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
  int first = 0, second = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    if(first <= A[i]) {
      second = first;
      first = A[i];
    }
    else if(second <= A[i]) {
      second = A[i];
    }
  }

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
