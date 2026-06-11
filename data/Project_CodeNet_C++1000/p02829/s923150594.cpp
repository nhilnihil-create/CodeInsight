#include <bits/stdc++.h>
using namespace std;

int main() {
  int A;
  cin >> A;
  int B;
  cin >> B;
  
  if (A==1 && B==2) {
    cout << 3;
  }
  if (A==1 && B==3) {
    cout <<2;
  }
  if (A==2 && B==3) {
    cout <<1;
  }
  if (A==3 && B==1) {
    cout <<2;
  }
  if (A==2 && B==1) {
    cout << 3;
  }
  if (A==3 && B==2) {
    cout <<1;
  }
	return 0;
}