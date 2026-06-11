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
	int M, N;
	cin >> N >> M;

	int sum = 0;
	vector<int> A(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
		sum += A[i];
	}

	int ok = 0;
	sort(A.begin(), A.end(), greater<int>());
	for (int i = 0; i < N; ++i)
	{
		if (4*M*A[i] >= sum)
			ok++;
		if (ok == M)
		{
			cout << "Yes\n";
			return;
		}
	}
	
	cout << "No\n";
	return;
}

int main() {
	//while(1)
	func();
	return 0;
}
