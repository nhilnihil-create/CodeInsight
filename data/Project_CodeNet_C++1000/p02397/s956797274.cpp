
#include <iostream>

using namespace std;

int x, y, smaller, bigger;

int main(){

	while (true){

		cin >> x >> y;

		if (x == 0 & y == 0){
			break;
		}

		if (x > y){

			bigger = x;
			smaller = y;
		}
		else{
			bigger = y;
			smaller = x;
		}

		cout << smaller << " " << bigger << endl;
	}

	return 0;
}




