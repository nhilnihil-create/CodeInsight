#include <iostream>
using namespace std;

int main () {

  int H, W;

  while (cin >> H >> W && H != 0 && W != 0){
    for (int i = 0; i < H; i++) {
      cout << "#" ;
      for (int j = 0; j < W-2; j++) {
	if (i == 0 || i == H-1) {
	  cout << "#";
	} else {
	  cout << "." ;
	}      
      }
      cout << "#\n" ;
    }
    cout << endl;
  }
  
  return 0;
}