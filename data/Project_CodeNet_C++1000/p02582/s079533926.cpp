#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
typedef long long ll;
const int N = 1010;

int main()
{
	char a[5];
	scanf("%s", a);
	
	int r = 0, ans = -1;
	for(int i = 0; i < 3; i++)
	{
		if(a[i] == 'R')	r++;
		else	r = 0;
		ans = max(ans, r);
	}
	printf("%d\n", ans); 
	return 0;
}

