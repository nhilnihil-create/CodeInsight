#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  int y,d,d1,sum=0;
  while(cin >> d){
    sum = 0;    
    d1 = d;
    for(;d<600;d+=d1){
      y = d*d*d1;
      sum += y;
    }
    cout << sum << endl;
  }
}
