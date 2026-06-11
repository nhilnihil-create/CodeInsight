#include <bits/stdc++.h>
using namespace std;

int main() {
	int X,Y;
  	cin >> X >> Y;
  
    int money;
  	
  	if(X <= 3){
      money += 100000 * (4-X);
    }
  
  	if(Y <= 3){
      money += 100000 * (4-Y);
    }
  
	if(X == 1 && Y == 1){
      money += 400000;
    }
  
  	cout << money << endl;

	return 0;
}
