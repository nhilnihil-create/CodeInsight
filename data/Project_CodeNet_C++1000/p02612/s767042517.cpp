#include<iostream>
#include<math.h>

using namespace std;

int main(void) {

	double n;
	int ans;
	
	cin >> n;

	if (fmod(n, 1000) == 0 || n == 0) {

		cout << 0;

	}
	else {

		ans = 1000 - fmod(n, 1000);
		cout << ans;

	}


	return 0;
}