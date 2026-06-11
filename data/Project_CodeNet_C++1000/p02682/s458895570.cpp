#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;


void func()
{
	int32_t A, B, C, K;
	int32_t ans(0);
	cin >> A >> B >> C >> K;

	if (K <= A)
	{
		cout << K << endl;
		return;
	}

	K -= A;
	if (K <= B)
	{
		cout << A << endl;
		return;
	}

	K -= B;
	cout << A-K << endl;

	return;
}

int main() {

//	while (1)
		func();
	return 0;
}
