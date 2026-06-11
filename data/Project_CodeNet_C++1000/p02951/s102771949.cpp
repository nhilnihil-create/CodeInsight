#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;

  int A, B, C;
  cin >> A >> B >> C;
  if(A - B > C){
    cout << 0 <<endl;
  } else{
    cout << C - A + B <<endl;
  }
}