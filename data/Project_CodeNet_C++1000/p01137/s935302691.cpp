#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int main(void){

  int e;

while(1){
    cin >> e;
    int ans = 100000000;
    if(e == 0) break;
      for(int y=0; y <= sqrt(e)+1; y++){
	for(int z=0;z <= cbrt(e)+1; z++){
	int x = e - y*y - z * z * z;
	  if(e == x + y*y + z*z*z && x >= 0){
	    ans = min(ans,x+y+z);
	    //cout << x << ' ' << y << ' ' << z << endl;
	  }
	}
      }

    cout << ans << endl;

 }
  return 0;
}