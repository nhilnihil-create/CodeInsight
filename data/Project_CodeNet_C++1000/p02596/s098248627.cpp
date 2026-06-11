#include<iostream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

int main() {
	 long long int K;
	 long long int X = 0;
	int ans = -1;
	cin >> K;
	for (int i = 0; i < 2*K; i++) {

		X = (10*X%K+7)%K;
		X = X % K;
		//cout << X << endl;
		
		if (X == 0) {
			ans = i + 1;
			break;
		}
	}
	
	cout << ans << endl;
	return 0;
}