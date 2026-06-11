#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int a[1000000];
int cnt = 0;
void insertionsort(int A[],int n ,int g)
{
	for (int i = g; i < n; ++i)
	{
		int v = A[i];
		int j = i-g;
		while(j>=0 && A[j]>v)
		{
			A[j+g] = A[j];
			j = j-g;
			cnt++;
		}
		A[j+g] = v;
	}
}


int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}

	vector<int> G;
	int h = 1;
	for (int i = 0; i < n; ++i)
	{
		if(h>n) break;
		G.push_back(h);
		h = 3*h+1;
	}
	int m = G.size();
	for (int i = m-1; i >= 0; --i)
	{
		insertionsort(a, n, G[i]);
	}

	printf("%d\n", m);
	for (int i = m-1; i > 0; --i)
	{
		printf("%d ", G[i]);
	}
	printf("%d\n", G[0]);

	printf("%d\n", cnt);
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}