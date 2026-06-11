#include<bits/stdc++.h>
using namespace std;

int main(void){
  int A, B, C;
  int cnt = 0;
  cin >> A >> B >> C;
  if(A == B)
    cnt++;
  if(B == C)
    cnt++;
  if(C == A)
    cnt++;
  if(cnt == 1) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}
