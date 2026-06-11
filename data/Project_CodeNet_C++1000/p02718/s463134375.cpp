#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	int* A = new int[N];
	int total = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		total += A[i];
	}

	double cond = 1.0 * total  / (4 * M) ;
	int num = 0;

	for (int i = 0; i < N; i++)
	{
		if (A[i] >= cond)
		{
			num++;
		}
	}

	//cout << "test: " << num << endl;

	if (num >= M)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	
}