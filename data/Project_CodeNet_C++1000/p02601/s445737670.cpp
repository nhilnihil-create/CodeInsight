#include<bits/stdc++.h>
using namespace std;

bool func(int a, int b, int c, int k, int i){
  if(k == i){
    return a < b && b < c;
  }
  return func(a*2, b, c, k, i+1) || func(a, b*2, c, k, i+1) || func(a, b, c*2, k, i+1);
}

int main(){
  int A, B, C, K;
  cin >> A >> B >> C >> K;
  cout << (func(A, B, C, K, 0) ? "Yes" : "No") << endl;
}