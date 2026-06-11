#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>
#include <math.h>

using namespace std;
double condition = 0.0;

void func()
{
	int K,N;
	cin >> K >> N;
	vector<int>A(N);

	for (int i = 0; i < N; i++)
		cin >> A[i];

	int diff = K-A[N-1]+A[0];
	for (int i = 1; i < N; ++i)
		diff = max(diff, A[i]-A[i-1]);

	cout << K - diff << endl;
}

int main() {
//	while(1)
	func();
	return 0;
}
