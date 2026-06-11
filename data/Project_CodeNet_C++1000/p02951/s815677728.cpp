#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int youki1 = A - B;
  int youki2 = C - youki1;
  
  if (youki2 >= 0) {
  	cout << youki2 << endl;
  } else {
  	cout << 0 << endl;
  }
}
