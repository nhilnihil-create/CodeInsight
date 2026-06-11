#include <iostream>
using namespace std;

int main(){

  int h, w;

  while(1) {

    cin >> h >> w;

    if(h == 0 && w == 0) break;

    for(int i=1; i<=w; i++) cout << "#";
    cout << "\n";
    
    for(int i=1; i<=h-2; i++) {
      cout << "#";
      for(int i=1; i<=w-2; i++) cout << ".";
      cout << "#";
      cout << "\n";  
    }
    
    for(int i=1; i<=w; i++) cout << "#";
    cout << "\n" << "\n";;
  }
    
  return 0;
}