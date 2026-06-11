#include <iostream>
#include <string>
using namespace std;

int row(int w);
  
int main() {


  int h, w;

  while(1) {
    cin >> h >> w;
    if((h + w) == 0) break;

    for(int j = 0; j < h; j++) {
      row(w);
    }
    cout << endl;
    
  }
  return 0;  
}      

int row(int w){

  for(int i = 0; i < w; i++) {
    cout << "#";
  }
  cout << endl;

  return 0;
}