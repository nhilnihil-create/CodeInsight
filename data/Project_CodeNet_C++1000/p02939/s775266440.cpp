#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 200005; 
int n;
char str[MAXN];

int main()
{
	scanf("%s",str+1);
	n = strlen(str+1);
	int ans = 0;
	string now = "", lst = "";
	for(int i = 1; i<=n; i++)
	{
		now += str[i];
		if(now!=lst)
			ans++, lst = now, now = "";
	}
	cout << ans << endl;
	return 0;
}
