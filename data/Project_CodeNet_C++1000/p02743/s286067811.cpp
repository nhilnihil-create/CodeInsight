#include <bits/stdc++.h>
using namespace std;

long long a,b,c;

int main()
{
	scanf("%d%d%d",&a,&b,&c);
	bool ok=4*a*b<(c-a-b)*(c-a-b) && c-a-b >= 0;
	puts(ok ?"Yes":"No");
	return 0;	
} 