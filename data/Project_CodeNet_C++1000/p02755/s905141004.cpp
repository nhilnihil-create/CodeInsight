#include <iostream>

using namespace std;

int main() {
	int A,B;

	cin >> A >> B;

	for(int money = 1; money < 2000;money++){
		if((int)(money*0.08) == A && money/10 == B){
			cout << money << endl;
			return 0;
		}
	}

	cout << -1 << endl;
	return 0;
}