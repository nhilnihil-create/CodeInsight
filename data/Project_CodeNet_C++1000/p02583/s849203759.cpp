# include <iostream>

using namespace std;

int main()
{
	int N;
	int* L;

	cin >> N;

	L = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> L[i];
	}

	int triangle=0;

	for (int i = 0; i < N-2; i++)
	{
		for (int j = i+1; j < N-1; j++)
		{
			for (int k = j+1; k < N; k++)
			{
				if (L[i] + L[j] > L[k] && L[i] + L[k] > L[j] && L[j] + L[k] > L[i])
				{
					if (L[i] != L[j] && L[i] != L[k] && L[j] != L[k])
					{
						triangle++;
					}
				}

			}
		}
	}

	cout << triangle;

	return 0;
}