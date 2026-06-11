#include <iostream>
using namespace std;

int main() {
  int l;
  cin >> l;
  int r;
  cin >> r;
  int d;
  cin >> d;
  int c = 0;
  
  int i = 0;
  while (i <= r){
    if (i >= l){
      c = c + 1;
    }
    i = i + d;
  }
  
  cout << c;
	return 0;
}