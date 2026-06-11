#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

main(){
  int e;
  while(cin >> e && e){
    int m = INF;
    for(int z=0;z*z*z<=e;z++){
      for(int y=0;y*y<=e-z*z*z;y++){
        int x = e-z*z*z-y*y;
        m = min(m, x + y + z);
      }
    }
    cout << m << endl;
  }
  return 0;
}