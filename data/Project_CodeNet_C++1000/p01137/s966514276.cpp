#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int y, z, E, res;
  
  while(cin >> E){
    if(!E) break;
    res = 1000000;
    for(z=0; z*z*z<=E; ++z){
      for(y=0; y*y+z*z*z<=E; ++y){
	res = min(res, E-(y*y+z*z*z) + y + z);
      }
    }
    cout << res << endl;
  }
  return 0;
}