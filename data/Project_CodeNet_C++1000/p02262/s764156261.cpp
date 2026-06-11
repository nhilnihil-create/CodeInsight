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
	{
		for(int j = i; j >= dis; j -= dis)
		{
			if(m[j] >= m[j-dis])
				break;
			else
			{
				int temp = m[j-dis];
				m[j-dis] = m[j];
				m[j] = temp;
				cnt++;
			}
		}
	}
}

void shell(int m[], int n)
{
	vector<int> v;
	int temp = 1;
	while(temp < n)
	{
		v.push_back(temp);
		temp = temp * 3 + 1;
	}
	printf("%d\n", v.size());
	printf("%d", v[v.size()-1]);
	insertion(m, v[v.size()-1], n);
	for(int i = v.size()-2; i >= 0; i--)
	{
		printf(" %d", v[i]);
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
	if(n == 1)
	{
		printf("1\n1\n0\n%d\n", m[0]);
		return 0;
	}
	shell(m, n);
	for(int i = 0; i < n; i++)
		printf("%d\n", m[i]);
	return 0;
}