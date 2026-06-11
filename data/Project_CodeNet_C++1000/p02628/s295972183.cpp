#include <iostream>
using namespace std;
int main()
{
	int K, N;
	cin >> N >> K;
	int p[1000];
	for (int i = 0; i < N; i++)
	{
		cin >> p[i];
	}
	int mim = p[0], index = 0, sum = 0;
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (mim > p[j] && p[j]!='\0')
			{
				mim = p[j];
				index = j;
			}
		}
		sum += mim;
		p[index] = '\0';
		for (int j = 0; j < N; j++)
		{
			if (p[j] != '\0')
			{
				mim = p[j];
				index = j;
				break;
			}
		}
	}
	cout << sum << endl;
}