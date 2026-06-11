#include <bits/stdc++.h>
using namespace std;

int main() {
  int wolf;
  int sheep;
  cin >> sheep;
  cin >> wolf;
  if(wolf<sheep){
    cout << "safe";
  }else{
    cout << "unsafe";
  }
	return 0;
}
