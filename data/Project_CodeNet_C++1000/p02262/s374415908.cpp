#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5;

int m[MAXN];
long long cnt;

void insertion(int m[], int dis, int n)
{
	for(int i = dis; i < n; i++)
		for(int j = i; j >= dis && m[j] < m[j - dis]; j -= dis)
		{
			int temp = m[j-dis];
			m[j-dis] = m[j];
			m[j] = temp;
			cnt++;
		}
}

void shell(int m[], int n)
{
	vector<int> v;
	int temp = 1;;
	do
	{
		v.push_back(temp);
		temp = temp * 3 + 1;
	}while(temp < n);
	printf("%d\n", v.size());
	for(int i = v.size()-1; i >= 0; i--)
	{
		printf("%d", v[i]);
		if(i)
			printf(" ");
		insertion(m, v[i], n);
	}
	cout << endl << cnt << endl;
}

int main()
{
	int n;
	cnt = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", m+i);

	shell(m, n);
	for(int i = 0; i < n; i++)
		printf("%d\n", m[i]);
	return 0;
}