#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int cun = 0;
	for(int i = 0; i < N ; i++) {
		if ((N - i) % 2 == 1) 
			cun++;
	}
	double NN = N;
	double cun2 = cun;
	double ans;
	ans = cun2 / NN;
	cout << ans << "\n";
}