#include <iostream>
using namespace std;

#define M 4
int a[M], b[M];

double sub_in(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (!(cin >> a[i]))
			return false;
	}
	return true;
}

bool in_ab(int a[], int b[], int n)
{
	if (!sub_in(a, n) || !sub_in(b, n))
		return false;
	return true;
}

int hit(int a[], int b[], int n)
{
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == b[i])
			c++;
	}
	return c;
}

int blow(int a[], int b[], int n)
{
	int c = 0;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (a[i] == b[j] && i != j)
				c++;
		}
	return c;
}

int main()
{
	while (in_ab(a,b,M))
	{
		cout << hit(a,b,M) << " " << blow(a,b,M) << endl;
	}
	return 0;
}