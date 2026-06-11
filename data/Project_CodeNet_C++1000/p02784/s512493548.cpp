#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, N;
  cin >> H >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  int sumA = 0;
  for(int i = 0; i < N; i++){
    sumA += A.at(i);
  }
  if(H <= sumA) cout << "Yes" << endl;
  else cout << "No" << endl;
}