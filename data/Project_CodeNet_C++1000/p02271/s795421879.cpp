#include<stdio.h>

int hantei2(int i, int a[], int n, int m) {
	int i1, i2;
	if (m == 0)
	{
		return 1;
	}
	else if (m < 0 || i >= n)
	{
		return 0;
	}
	
	
	i1 = hantei2(i + 1, a, n, m - a[i]);
	i2 = hantei2(i + 1, a, n, m);

	if (i1 == 1 || i2 == 1) return 1;
}


int hantei(int a[], int n, int m) {
	int i = 0;
	return hantei2(i, a, n, m);
}

int main(void) {
	int a[20], n, m, q, i, h;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	scanf("%d", &q);
	for (i = 0; i < q; i++)
	{
		scanf("%d", &m);
		h = hantei(a, n, m);
		if (h == 1)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	
	return 0;
}