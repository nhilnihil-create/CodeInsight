#include<bits/stdc++.h>
using namespace std;

bool check(int A, int B, int C, int K, int i){
  if(i == K){
    return A < B && B < C;
  }
  return check(A*2, B, C, K, i+1) || check(A, B*2, C, K, i+1) || check(A, B, C*2, K, i+1);
}

int main(){
  int A, B, C, K;
  cin >> A >> B >> C >> K;
  cout << (check(A, B, C, K, 0) ? "Yes" : "No") << endl;
}