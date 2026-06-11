#include <iostream>
using namespace std;

int main() {
	int x;
  cin >> x;
  if (x >= 400 && x <= 599){
    cout << '8';
  }
  if (x >= 600 && x <= 799){
    cout << '7';
  }
  if (x >= 800 && x <= 999){
    cout << '6';
  }
  if (x >= 1000 && x <= 1199){
    cout << '5';
  }
  if (x >= 1200 && x <= 1399){
    cout << '4';
    
  }
  if (x >= 1400 && x <= 1599){
    cout << '3';
    
  }
  if (x >= 1600 && x <= 1799){
    cout << '2';
    
  }
  if (x >= 1800 && x <= 1999){
    cout << '1';
    
  }
	return 0;
}
