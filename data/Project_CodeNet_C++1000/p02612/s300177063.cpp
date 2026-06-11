#include <bits/stdc++.h>
using namespace std;

int main() {
  int a = 0;
  cin >> a;
  int m = a % 1000;
  if (m == 0){
    cout << 0;
  }else{
  int v = 1000 - m;
  cout << v;
    }
	return 0;
}
