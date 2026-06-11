#include <iostream>
using namespace std;
 
int main() {
	int x;
  	string y;
  
  	cin >> x;
    
    switch (x) {
      case 1:
        y = "0";
        break;
      case 0:
        y = "1";
        break;
    }
  
  	cout << y << endl;
  
    return 0;
    }
