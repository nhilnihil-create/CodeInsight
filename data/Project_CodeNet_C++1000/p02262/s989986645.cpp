#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

long long cnt;
int l, a[1000000], n;
vector<int> G;

void insertion_sort(int a[], int n, int g)
{
	for(int i = g; i < n; i++)
	{
		int v = a[i];
		int j = i - g;
		while(j >= 0 && a[j] > v)
		{
			a[j + g] = a[j];
			j -= g;
			cnt++;
		}
		a[j + g] = v;
	}
}

void shell_sort(int a[], int n)
{
	for(int h = 1; ; )
	{
		if(h > n)
		{
			break;
		}
		G.push_back(h);
		h = 3 * h + 1;
	}
	for(int i = G.size()-1; i >= 0; i--)
	{
		insertion_sort(a,n,G[i]);
	}
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	cnt = 0;
	shell_sort(a,n);
	cout << G.size() << endl;
	for(int i = G.size() - 1; i >= 0; i--)
	{
		printf("%d", G[i]);
		if(i)
		{
			printf(" ");
		}
	}
	cout << endl;
	cout << cnt << endl;
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
	
	return 0;
}
