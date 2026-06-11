#include <iostream>
using namespace std;

int main(){

  int h, w;

  while(1) {

    cin >> h >> w;

    if(h == 0 && w == 0) break;
    
    for(int i=1; i<=h; i++) {
      for(int i=1; i<=w; i++) cout << "#";
      cout << "\n";  
    }
    cout << "\n";
  }
    
  return 0;
}