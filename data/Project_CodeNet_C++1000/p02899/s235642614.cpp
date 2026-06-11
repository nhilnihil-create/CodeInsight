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
  vector<int> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<int> rev(N);
  for(int i = 0; i < N; i++) {
    rev[A[i] - 1] = i + 1;
  }

  for(int i = 0; i < N; i++) {
    cout << rev[i];
    if(i == N - 1) {
      cout << endl;
    }
    else {
      cout << " ";
    }
  }

  return 0;
}
