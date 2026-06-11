#include <iostream>

using namespace std;

#define N 100

int main()
{
	int m[N][N] = {0};
	
	int n;	cin >> n;

	int v, in, out;
	for (int i = 0; i < n; ++i)
	{
		cin >> in >> v;
		for (int j = 0; j < v; ++j)
		{
			cin >> out;
			m[in - 1][out - 1] = 1;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << m[i][j];
			if (j != n - 1) cout << " ";
			else cout << endl;
		}
	}

	return 0;
}