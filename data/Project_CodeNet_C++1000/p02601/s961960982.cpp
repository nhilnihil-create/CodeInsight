#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int A, B, C, K; cin >> A >> B >> C >> K;
  int cnt = 0;
  for(int i = 0; A >= B && i < K; i++) {
    B *= 2;
    cnt++;
  }
  C *= pow(2, K - cnt);
  if(A < B && B < C) cout << "Yes" << endl;
  else cout << "No" << endl;
}