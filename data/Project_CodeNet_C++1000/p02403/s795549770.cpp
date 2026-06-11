#include <iostream>
using namespace std;
int main(void){
  int width, height;
  
  while(true) {
    cin >> height >> width;
    
    if(height == 0 && width == 0) {
      break;
    }
    
    string rect(width, '#');
    for(int i = 0; i < height; i++) {
      cout << rect << endl;
    }
    cout << endl;
  }
}