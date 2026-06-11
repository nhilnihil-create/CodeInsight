#include<iostream>
using namespace std;

int main(){
  int height;
  int width;
  while(true){
    cin >> height >> width;
    if(height == 0 && width == 0)
      break;
    for (int i = 0; i < height; i++){
      for (int j = 0; j < width; j++){
        if (i == 0 || i == height - 1){
          cout << "#";
        }
        else if (j == 0 || j == width - 1){
          cout << "#";
        }
        else {
          cout << ".";
        }
      }
      cout << "\n";
    }
    cout << "\n";
  }
  return 0;
}

