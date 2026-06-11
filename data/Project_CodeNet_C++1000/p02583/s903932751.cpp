#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
typedef long long ll;
const int N = 110;
int n;
int a[N];

bool judge(int a, int b, int c)
{
	return a + b > c && a + c > b && b + c > a; 
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)	scanf("%d", &a[i]);
	
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			if(a[j] != a[i])
			{
				for(int k = j + 1; k <= n; k++)
				{
					if(a[k] != a[j] && a[k] != a[i])
					{
						if(judge(a[i], a[j], a[k]))
						{
							ans++;
						}
					}
				}
				
			}
		}
	}
	
	printf("%d", ans); 
	return 0;
}

