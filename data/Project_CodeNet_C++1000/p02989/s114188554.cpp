#include <bits/stdc++.h>
using namespace std;
#define rep(i,A) for(int i = 0;i < A;i++)

int main() {
  int A;
  cin >> A;
  int B[100100];
  int C = A / 2;
  int D = A / 2 - 1;
  rep(i,A){
   cin >> B[i]; 
  }
 sort(B,B + A);
  int Ans = B[C] - B[D];
  cout << Ans << endl;
}
