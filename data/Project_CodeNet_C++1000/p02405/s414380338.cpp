#include <iostream>
using namespace std;
  
void PrintCheckFirstSharp (int length) {
  for ( int i = 0; i < length; ++i) {
    if ( i % 2 == 0 ) {
      cout << '#';
    } else {
      cout << '.';
    }
  }
  cout << endl;
}
  
void PrintCheckFirstDot ( int length ) {
  for ( int i = 0; i < length; ++i ){
    if ( i % 2 == 0 ) {
      cout << '.';
    } else {
      cout << '#';
    }
  }
  cout << endl;
}
  
void PrintArea( int H, int W ) {
  for ( int i = 0; i < H; ++i ) {
    if ( i % 2 == 0 ) {
      PrintCheckFirstSharp( W );
    } else {
      PrintCheckFirstDot( W );
    }
  }
  cout << endl;
}
  
int main() {
  while (true) {
    int H, W;
    cin >> H >> W;
    if (H == 0 && W == 0) break;
    PrintArea(H, W);
  }
  return 0;
};