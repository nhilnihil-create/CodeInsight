#include<iostream>
#include<cstdio>
#include<algorithm>
#include<sstream>
#include<string>
#include<string.h>
#include<cmath>
#include<stack>
#include<vector>
#include<map>
#define E (2.71828182)
#define PI (3.1415926535898)
#define	mem(a,b)	memset(a,b,sizeof(a))
#define	_max(a,b,c)	(max(a,b)>c?max(a,b):c)
#define mod	1000000007
#include<set>
#define gc getchar
#define debug(a) cout << "*" << a << "*" << endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<float, int> P;
const int N = 200000;
const long long  MAX_V = 5005, INF = 2147483647, MOD = 998244353;
#include <iostream>
using namespace std;
char sp[1000005];
int ans;
int main()
{
	while (~scanf("%s", sp))
	{
		ans = 0;
		for (int i = strlen(sp) - 1; i > 0; i--)
		{
			if (sp[i] > '5')
			{
				ans += 10 - sp[i] + '0';
				sp[i - 1]++;
			}
			else if (sp[i] < '5')
			{
				ans += sp[i] - '0';
			}
			else
			{
				if (sp[i - 1] >= '5')
				{
					ans += 10 - sp[i] + '0';
					sp[i - 1]++;
				}
				else
				{
					ans += sp[i] - '0';
				}
			}
		}
		if (sp[0] <= '5')	ans += sp[0] - '0';
		else ans += 11 - sp[0] + '0';
		printf("%d\n", ans); 
	}
}
