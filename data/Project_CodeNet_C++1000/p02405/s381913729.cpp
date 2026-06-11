#include<iostream>
using namespace std;

int main() {

  int wide,high;

  while(cin >> high >> wide) {

    if (high == 0 || wide == 0) {
      break;
    }
    
    for (int i = 1; i <= high; i++) {
      for (int j = 1; j <= wide; j++) {
	if (i%2 == 1 && j%2 == 1) {
	  cout << '#' ;
	} else if (i%2 == 0 && j%2 == 0) {
	  cout << '#' ;
	} else if (i%2 == 0 && j%2 == 0) {
	  cout << '.' ;
	} else {
	  cout << '.';
	}
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;

}