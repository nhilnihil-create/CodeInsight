# include <iostream>
# include <math.h>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int* A = new int[N];
	int* B = new int[N];

	for (int i = 0; i < N; i++)
	{
		B[i] = 0;
	}
	for (int i = 1; i < N; i++)
	{
		cin >> A[i];
		B[A[i]-1]++;
	}

	for (int i = 0; i < N; i++)
	{
		cout << B[i] << endl;
	}

	return 0; 
}