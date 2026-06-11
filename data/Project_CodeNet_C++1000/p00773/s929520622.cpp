#include <iostream>
using namespace std;


int x, y, s;

int main(){
  while(true){
    cin >> x;
    cin >> y;
    cin >> s;
    if (x == 0 && y == 0 && s == 0)break;

    int bef, aft, max;
    max = 0;
  
    for (int i = 1; i<=s; ++i){
      for (int j = 1; j<=s; ++j){
	bef = i * (100 + x) / 100 + j * (100 + x) / 100;
	if (bef == s){
	  aft = i * (100 + y) / 100 + j * (100 + y) / 100;
	  if(aft >= max){
	    max = aft;
	    //cout << "ijmax" << i << " " << j << " " << max << endl;
	  }
	}
      }
    }
    cout << max << endl;
  }
}