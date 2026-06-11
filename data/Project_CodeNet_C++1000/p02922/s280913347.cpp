#include<bits/stdc++.h>
using namespace std;
int main() {
  int A, B, mouse, res = 1;
  cin >> A >> B;
  mouse = A;
  A--;
  while(mouse < B) {
    mouse += A;
    res++;
  }
  if(B == 1) res = 0;
  cout << res << endl;
}