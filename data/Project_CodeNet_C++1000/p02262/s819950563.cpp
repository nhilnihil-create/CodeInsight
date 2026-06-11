#include<iostream>

using namespace std;

long long cnt = 0;

void insertion(int a[], int n, int g)
{
	int i, j, v;
	for (i = g; i < n; i++)
	{
		v = a[i];
		j = i - g;
		while (j >= 0 && a[j] > v)
		{
			a[j + g] = a[j];
			j -= g;
			cnt++;
		}
		a[j + g] = v;
	}
}

int make(int g[], int n)
{
	g[0] = 1;
	int i;
	for (i = 1;; i++)
	{
		g[i] = 3 * g[i - 1] + 1;
		if (g[i] > n)
		{
			return i;
		}
	}
}

int main()
{
	int n, a[1000000];
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	int m, g[35];
	m = make(g, n);
	for (int i = m - 1; i >= 0; i--)
	{
		insertion(a, n, g[i]);
	}
	cout << m << endl << g[m - 1];
	for (int i = m - 2; i >= 0; i--)cout << " " << g[i];
	cout << endl << cnt << endl;
	for (int i = 0; i < n; i++)cout << a[i] << endl;
    return 0;
}