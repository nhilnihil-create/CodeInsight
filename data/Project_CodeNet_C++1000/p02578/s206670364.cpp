#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	vector<int> A;

	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	/*
	N = 5;
	A[0] = 2;
	A[1] = 1;
	A[2] = 5;
	A[3] = 4;
	A[4] = 3;
	*/

	long long s = 0;
	int max = 0;
	int dif;

	for (int i = 0; i < N; i++)
	{
		dif = max - A[i];
		s += dif > 0 ? dif : 0;
		max = dif > 0 ? max : A[i];
		//cout << "max = " << max << endl;
	}
	cout << s << endl;
	return (0);
}
