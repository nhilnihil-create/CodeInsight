# include <iostream>
# include <math.h>

using namespace std;

int main()
{
	int N, M, sum = 0;
	int* A;

	cin >> N >> M;
	A = new int[M];

	for (int i = 0; i < M; i++)
	{
		cin >> A[i];
		sum += A[i];
	}
	int rest = N - sum;

	if (rest < 0)
		cout << "-1";
	else
		cout << rest;


	return 0; 
}