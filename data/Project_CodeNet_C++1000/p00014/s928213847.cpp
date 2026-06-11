#include<iostream>

using namespace std;

int main(void) {
	int d;
	long long res;
	int i;

	while(!cin.eof()) {
		cin >> d;
		res = 0;
		for(i = d; i < 600; i+=d) {
			res += i*i*d;
		}
		if(!cin.eof()) { cout << res << endl; }
	}

	return 0;
}