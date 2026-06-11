#include <iostream>

using namespace std;

char toMark(int x){
  switch(x){
    case 0:
    return 'S';
    case 1:
    return 'H';
    case 2:
    return 'C';
    case 3:
    default:
    return 'D';
  }
}

int toNum(char x){
  if(x == 'S') return 0;
  if(x == 'H') return 1;
  if(x == 'C') return 2;
  if(x == 'D') return 3;
}

int main() {
  int n;
  int number;
  char mark;
  bool cards[4][13] = {false};
  cin >> n;
  for(int i=0; i < n; ++i){
    cin >> mark >> number;
    cards[toNum(mark)][number-1] = true;
  }
  for(int i=0; i < 4; ++i){
    for(int j=0; j < 13; ++j){
      if(cards[i][j] == false) cout << toMark(i) << " " << j+1 << endl;
    }
  }
  return 0;
}
