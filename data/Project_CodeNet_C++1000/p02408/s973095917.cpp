#include<iostream>
using namespace std;

int main(){
  bool cards[4][13];
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 13; j++){
      cards[i][j] = false;
    }
  }

  int n, x;
  char A;
  cin >> n;

  for (int i = 0; i < n; i++){
    cin >> A >> x;
    if ( A == 'S' ) cards[0][x-1] = true;
    else if ( A == 'H' ) cards[1][x-1] = true;
    else if ( A == 'C' ) cards[2][x-1] = true;
    else if ( A == 'D' ) cards[3][x-1] = true;

  }

  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 13; j++){
      if (cards[i][j] == false) {
        if (i == 0) cout << 'S' << " " << j + 1 << endl;
        else if (i == 1) cout << 'H' << " " << j + 1 << endl;
        else if (i == 2) cout << 'C' << " " << j + 1 << endl;
        else if (i == 3) cout << 'D' << " " << j + 1 << endl;
      }
    }
  }

return 0;
}