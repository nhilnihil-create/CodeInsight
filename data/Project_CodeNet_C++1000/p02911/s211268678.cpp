#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, K, Q;
  cin >> N >> K >> Q;
  vector<int> A(Q), B(N);
  for (int i = 0; i < Q; i++) {cin >> A.at(i);}
  for (int i = 0; i < N; i++) {B.at(i) = K - Q;}
  for (int i = 0; i < Q; i++) {
    int R = A.at(i);
    B.at(R - 1)++;
  }
  for (int i = 0; i < N; i++) {
    if (B.at(i) > 0) {cout << "Yes" << endl;}
    else {cout << "No" << endl;}
  }
}