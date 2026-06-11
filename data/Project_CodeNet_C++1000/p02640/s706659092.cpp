#include <iostream>
using namespace std;

int main(){
  int x,y,legs;
  cin >> x >> y;
  legs = x * 2;
  while(legs <= x * 4){
    if (legs == y){
      cout << "Yes" << endl;
      return 0;
    }
    legs += 2;
  }
  cout << "No" << endl;
  return 0;
}