#include <iostream>
using namespace std;

int main(){

  int h, w, i, j;

  while(1) {
    cin >> h >> w;
    if(h ==0 && w ==0) break;

    for(i = 1; i <= h; i++) {
      for(j = 1; j <= w; j++) {
	if( (i+j) % 2 == 0) cout << "#";
	else cout << ".";
      }
      cout << "\n";
    }
    cout << "\n";
  }
  return 0;
}