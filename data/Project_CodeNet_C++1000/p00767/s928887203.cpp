#include <iostream>

int diagonal[151][151];

using namespace std;

int main(void){

  for(int i = 0 ; i < 151 ; i++){
    for(int j = 0 ; j < 151 ; j++){
      diagonal[i][j] = i * i + j * j;
    }
  }

  while(1){
    int h, w;
    cin >> h;
    cin >> w;
    if(h == 0 && w == 0) {return 0;}

    int tmp = h * h + w * w;
    bool find = false;

    for(int i = h ; i < 151 && !find ; i++){
      for(int j = 1 ; j < 151 && !find ; j++){
        if(diagonal[i][j] == tmp && i < j && !(i == h && j == w)){
          find = true;
          cout << i << " " << j << endl;
        }
      }
    }

    for(int step = 1 ; !find ; step++){
      for(int i = 1 ; i < 151 && !find ; i++){
        for(int j = 1 ; j < 151 && !find ; j++){
          if(diagonal[i][j] == tmp + step && i < j && !(i == h && j == w)){
            find = true;
            cout << i << " " << j << endl;
          }
        }
      }
    }
  }

  return 0;
}
