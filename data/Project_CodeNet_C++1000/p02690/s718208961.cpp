#include <iostream>
#include <vector>

using namespace std;



int main(void) {
	int X;
	cin >> X;
	int delta = 1;
	int A = 120;
	int B = A-delta;
	long long test;
	bool find = false;
	while (!find) {
		//AとBの更新
		A -= 1;
		B = A - delta;
		if (B < -119) {
			//差を更新
			delta += 1;
			A = 120;
			B = A - delta;
		}
		test = (A*A*A*A*A) - (B*B*B*B*B);
		if (test == X) find = true;
	}
	cout << A << " "<< B<<endl;
	return 0;
}