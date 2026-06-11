#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_LENGTH = 1024;

char A[MAX_LENGTH + 1];
char B[MAX_LENGTH + 1];

int tu[MAX_LENGTH][MAX_LENGTH];

void lcs(int, int);

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> A >> B;
		int lA = strlen(A), lB = strlen(B);
		lcs(lA, lB);
		cout << tu[lA][lB] << endl;
	}

}

void lcs(int lA, int lB)
{
	for (int i = 0; i < lA; ++i)
		tu[0][i] = 0;
	for (int i = 0; i < lB; ++i)
		tu[i][0] = 0;

	for (int i = 1; i <= lA; i++)
	{
		for (int j = 1; j <= lB; j++)
		{
			if (A[i-1] == B[j-1])
				tu[i][j] = tu[i - 1][j - 1] + 1;
			else
				tu[i][j] = max(tu[i][j - 1], tu[i - 1][j]);
		}
	}
}