#include <bits/stdc++.h>
using namespace std;

int main() {
  int ar = 0;
  cin >> ar;
  int maradek = ar % 1000;
  if (maradek == 0){
    cout << 0;
    return 0;
  }
  int mo = 1000 - maradek;
  cout << mo;
	return 0;
}
