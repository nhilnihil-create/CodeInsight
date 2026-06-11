#include "iostream"
using namespace std;

int main()
{
	int n;
	cin >> n;
	int info[4][3][10] = {};
	
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		info[a-1][b-1][c-1] += d;
	}
	for (int i = 0; i < 15; i++)
	{
		if ((i + 1) % 4 == 0) {
			for (size_t i = 0; i < 20; i++)
			{
				cout << '#';
			}
			cout << endl;
		}
		else {
			for (int j = 0; j < 10; j++)
			{
				cout <<" "<< info[(i + 1) / 4][(i + 1) % 4-1][j];
			}
			cout << endl;
		}
	}
	return 0;
}