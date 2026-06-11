#include <iostream>
using namespace std;

int main(void){
  int card[4][13] = {0};
  int N;
  cin >> N;
  char k;
  int number;
  for(int i = 0; i < N; i++ ){
    cin >> k >> number;
    if( k == 'S') card[0][number-1] = 1;
    if( k == 'H') card[1][number-1] = 1;
    if( k == 'C') card[2][number-1] = 1;
    if( k == 'D') card[3][number-1] = 1;
  }
  for(int j = 0; j < 4; j++ ){
    for(int k = 0; k < 13; k++ ){
      if( card[j][k] == 0 ){
        if( j == 0 ) cout << "S" << " " << (k+1) << endl;
        if( j == 1 ) cout << "H" << " " << (k+1) << endl;
        if( j == 2 ) cout << "C" << " " << (k+1) << endl;
        if( j == 3 ) cout << "D" << " " << (k+1) << endl;
      }
    }
  }


  return 0;
}