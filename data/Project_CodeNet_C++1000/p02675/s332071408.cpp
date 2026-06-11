#include <bits/stdc++.h>
using namespace std;

int main() {
	int a;
  cin >> a;
  a = a % 10;
  if(a == 2 || a == 4 || a == 5 || a == 7 || a == 9){
    cout << "hon" << endl;
  }
  if(a == 0 || a == 1 || a == 6 || a == 8){
    cout << "pon" << endl;
  }
  if(a == 3){
    cout << "bon" << endl;
  }
	return 0;
}
