#include <iostream>
using namespace std;
int n;
int m =0;
int *a;
//int  G[16] = { 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
int G[100] = {};
int Gn = 0;

void insert_sort(int g)
{
	for(int i=g;i<n;i++)
	{
		int key = a[i];
		int j=i-g;
		while(j>=0)
		{
			if(a[j]<=key) 
			{
  			  break;
			}
			a[j+g] = a[j];
			m++;
			j -= g;
		}
		a[j+g] = key;
	}
}

void shell_sort()
{
	for (int i=0; i<Gn;i++)
	{
		insert_sort(G[Gn-1-i]);
	}
}

int main()
{
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n;	i++)
	{
		cin >> a[i];
	}
	
	Gn = 1;
	G[0] = 1;
	int g = 2;
	while (g + 1< n)
	{
		G[Gn++] = g + 1;
		g *= 2;
	}
	
	shell_sort();
	
	cout << Gn << endl;
	for (int i=0; i<Gn;i++)
	{
		if (i) cout << ' ';
		cout << G[Gn-1-i];
	}
	cout << endl;
	
	cout << m << endl;
	
	for (int i=0; i<n;	i++)
	{
		cout << a[i] << endl;
	}
	
	return 0;
}