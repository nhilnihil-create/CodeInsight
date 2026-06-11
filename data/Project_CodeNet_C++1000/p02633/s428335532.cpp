#include<bits/stdc++.h>
using namespace std;
int x;
int main()
{
	scanf("%d",&x);
	printf("%d\n",x/__gcd(x,360)*360/x);
	return 0;
}